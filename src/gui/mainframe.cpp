/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU Lesser General Public License as published by *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU Lesser General Public License for more details.                         *
 *                                                                                *
 *    You should have received a copy of the GNU Lesser General Public License    *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

#include "mainframe.h"

#include <functional>
#include <algorithm>

#include <boost/filesystem.hpp>

#include <utils/utils.h>
#include <renderEngine/shape.h>

#include "renderwindow.h"
#include "id.h"

const long MainFrame::ID_NOTEBOOK = wxNewId();

MainFrame::MainFrame(wxWindow *parent,wxWindowID id,std::string const &title)
:wxFrame(parent,id,title)
,m_menuTree(boost::filesystem::path(AppConfig::buildPath(AppConfig::INFO::MENU)))
{
    m_auiManager.SetManagedWindow(this);
    m_auiNotebookWorkspace = new wxAuiNotebook(this, ID_NOTEBOOK);

//add first page to notebook
    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
	RenderWindow *first=new RenderWindow((wxFrame*)m_auiNotebookWorkspace,args,
										 Color(0,0,0,1),Color(0,1,0,1)//!\todo remove those constants. Maybe use a config file entry?
										);
    m_auiNotebookWorkspace->AddPage(first, "Map 1", true);
	m_plans.push_back(first);
    m_active=m_plans.begin();

    m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Center());
    m_auiManager.Update();

	m_actionPlugIn.acceptProviderType<PluginProvider>();
	m_menuTree.buildMenu(boost::filesystem::path(AppConfig::buildPath(AppConfig::MENU)));

	loadRequestedPlugins();

	m_menuTree.create();
	SetMenuBar(m_menuTree.getMenuBar());

	m_auiManager.Update();
}

MainFrame::~MainFrame(void)
{
	for(auto &i:m_plugins)//!\todo find a way to let unique_ptr<> do the delete job when destroyed by vector's destruction
		i.second.reset();

	m_auiManager.UnInit();
}

void MainFrame::changeSelectedPlugin(wxCommandEvent& event)
{
	static int oldId=0;
	if(oldId)//!\todo and what if it was the first plugin loaded?
		m_plugins[oldId]->removeEventManager();
	oldId=event.GetId();
	m_plugins[oldId]->installEventManager(**m_active);
}

void MainFrame::loadRequestedPlugins(void)
{
	for(auto &i:m_menuTree)//only browse leaves
	{
		std::string plugName=i.getPluginName();
		auto jt=m_buttonIDs.find(plugName);
		if(jt==m_buttonIDs.end())// plugin is not loaded? Try to load it.
		{
			assert(!m_actionPlugIn.isLoaded(plugName));//!\note should never load twice the same plugin. Could be in pluma...
			PluginProvider* plugProvider=getProvider<PluginProvider>(m_actionPlugIn,AppConfig::buildPath(AppConfig::PLUGINS),plugName);
			if(nullptr!=plugProvider)
			{
				ID tmp(m_buttonIDs[plugName]);// avoid searching twice in the map
				m_plugins[tmp].reset(plugProvider->create());
				i.setID(tmp);
			}
			else
				i.disable();
		}
		if(i.isEnabled())
		{
			jt=m_buttonIDs.find(plugName);
			if(jt!=m_buttonIDs.end())// plugin loaded? Bind it.
				Bind(wxEVT_COMMAND_MENU_SELECTED,&MainFrame::changeSelectedPlugin,this,jt->second,jt->second);
		}
	}
}
