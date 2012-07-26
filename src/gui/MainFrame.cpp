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

#include "MainFrame.h"

#include <functional>
#include <algorithm>

#include <boost/filesystem.hpp>

#include <renderEngine/vertex.h>
#include <renderEngine/point.h>
#include <renderEngine/shape.h>

#include "RenderWindow.h"
#include "id.h"
#include "../utils/utils.h"

const long MainFrame::ID_NOTEBOOK = wxNewId();

MainFrame::~MainFrame(void)
{
	for(auto &i:m_plugins)//!\todo find a way to let unique_ptr<> do the delete job when destroyed by vector's destruction
		i.second.reset();

	m_auiManager.UnInit();
}

MainFrame::MainFrame(wxWindow *parent,wxWindowID id,std::string const &title)
:wxFrame(parent,id,title)
,m_menuTree(boost::filesystem::path(AppConfig::buildPath(AppConfig::INFO::MENU)))
,m_plans()
,m_active()
,m_auiManager()
,m_auiNotebookWorkspace()
,m_actionProviders()
,m_plugins()
,m_actionPlugIn()
{
    m_auiManager.SetManagedWindow(this);
    m_auiNotebookWorkspace = new wxAuiNotebook(this, ID_NOTEBOOK);

//add first page to notebook
    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
	RenderWindow *first=new RenderWindow((wxFrame*)m_auiNotebookWorkspace,args);
    m_auiNotebookWorkspace->AddPage(first, "Map 1", true);
    m_plans.push_back(first);
    m_active=m_plans.begin();

    m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Name(_T("Workspace")).Caption(_("Workspace")).CaptionVisible(false).CloseButton(false).Center());
    m_auiManager.Update();

	m_actionPlugIn.acceptProviderType<PluginProvider>();
	m_menuTree.buildMenu(boost::filesystem::path(AppConfig::buildPath(AppConfig::INFO::MENU)));

	loadRequestedPlugins();

	m_menuTree.create();
	SetMenuBar(m_menuTree.getMenuBar());

	m_auiManager.Update();
}

void MainFrame::onQuit(wxCommandEvent& event)
{
    Close();
}

void MainFrame::changeSelectedPlugin(wxCommandEvent& event)
{
	static int oldId=0;
	if(oldId)
		m_plugins[oldId]->removeEventManager();
	oldId=event.GetId();
	m_plugins[oldId]->installEventManager(**m_active);
}

void MainFrame::loadRequestedPlugins(void)
{
	//load only needed plugins
	for(auto it=m_menuTree.begin();it!=m_menuTree.end();++it)//only browse leaves
	{
		std::string plugName=it->getPluginName();
		auto jt=m_buttonIDs.find(plugName);
		if(jt==m_buttonIDs.end())// plugin is not loaded? Try to load it.
		{
			assert(!m_actionPlugIn.isLoaded(plugName));//!\note should never load twice the same plugin. Could be in pluma...
			PluginProvider* plugProvider=getProvider<PluginProvider>(m_actionPlugIn,AppConfig::buildPath(AppConfig::INFO::PLUGINS),plugName);
			if(nullptr==plugProvider)
				it->disable(); //!\todo implement an action for this
			else
			{
				m_plugins[m_buttonIDs[plugName]].reset(plugProvider->create());
				it->setID(m_buttonIDs[plugName]);
			}
		}
		//!\todo do not bind buttons if the plugin has been disabled
		jt=m_buttonIDs.find(plugName);
		if(jt!=m_buttonIDs.end())// plugin loaded? Bind it.
			Bind(wxEVT_COMMAND_MENU_SELECTED,&MainFrame::changeSelectedPlugin,this,jt->second,jt->second);
	}
}
