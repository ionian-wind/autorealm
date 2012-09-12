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
#include <renderEngine/color.h>
#include <pluginEngine/drawer.h>

#include "renderwindow.h"
#include "id.h"

const long MainFrame::ID_NOTEBOOK = wxNewId();

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, std::string const &title)
	: wxFrame(parent, id, title)
	, m_menuTree(boost::filesystem::path(AppConfig::buildPath(AppConfig::INFO::MENU)))
{
	initialize();
//create the notebook and add it an empty page
	createFirstPage();
	loadRequestedPlugins();
	setDefaultRenderers();
	m_auiManager.Update();
}

MainFrame::~MainFrame(void)
{
	//event manager cleanup
	wxCommandEvent e;
	e.SetId(0);
	changeSelectedPlugin(e);

	for(std::pair<ID,Plugin*> i : m_plugins)
		delete i.second;

	m_auiManager.UnInit();
}

void MainFrame::changeSelectedPlugin(wxCommandEvent &event)
{
	static int oldId = 0;

	if(oldId)
		m_plugins[oldId]->removeEventManager();

	oldId = event.GetId();
	if(oldId)
		m_plugins[oldId]->installEventManager();
}

void MainFrame::createFirstPage(void)
{
	int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
	RenderWindow *first =
		new RenderWindow((wxFrame *)m_auiNotebookWorkspace,
						 args
						);
	m_auiNotebookWorkspace->AddPage(first, "Map 1", true);

	/*
	find the good Drawer in m_drawerList thanks to its TagList (contained in AppConfig)
	use it to generate a Renderer
	assign that Renderer to the correct "color" : border or filler
	*/
//	first->setBorder(AppConfig::getRenderer());
	m_plans.push_back(first);
	m_active = m_plans.begin();
}

void MainFrame::loadRequestedPlugins(void)
{
	for(Component<MenuConverter> &i : m_menuTree) //only browse leaves
	{
		std::string plugName = i.getPluginName();
		AssocIDs::iterator jt = m_buttonIDs.find(plugName);

		if(jt == m_buttonIDs.end()) // plugin is not loaded? Try to load it.
		{
			assert(!m_actionPlugIn.isLoaded(plugName));///\note should never load twice the same plugin. Could be in pluma...
			PluginProvider *plugProvider = getProvider<PluginProvider>(m_actionPlugIn, AppConfig::buildPath(AppConfig::PLUGINS), plugName);

			if(nullptr != plugProvider)
			{
				ID tmpid(m_buttonIDs[plugName]);// avoid searching twice in the map
				Plugin* tmpplug=plugProvider->create(*m_active);
				m_plugins[tmpid]=tmpplug;
				i.setID(tmpid);
				if(Drawer* tmpDrawer=dynamic_cast<Drawer*>(tmpplug))
					m_drawerList.push_back(tmpDrawer);
			}
			else
				i.disable();
		}

		if(i.isEnabled())
		{
			jt = m_buttonIDs.find(plugName);

			if(jt != m_buttonIDs.end()) // plugin loaded? Bind it.
				Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::changeSelectedPlugin, this, jt->second, jt->second);
		}
	}
}

void MainFrame::initialize(void)
{
	m_auiManager.SetManagedWindow(this);
	m_actionPlugIn.acceptProviderType<PluginProvider>();
	m_menuTree.create();
	SetMenuBar(m_menuTree.getMenuBar());
	m_auiNotebookWorkspace = new wxAuiNotebook(this, ID_NOTEBOOK);
	m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Center());
}

void MainFrame::setDefaultRenderers(void)
{
	for(Drawer *i:m_drawerList)
	{
		if((*i)==AppConfig::getRenderer(AppConfig::RENDERER::BORDER))
			(*m_active)->setBorder(*i);
		if((*i)==AppConfig::getRenderer(AppConfig::RENDERER::FILLER))
			(*m_active)->setBorder(*i);
	}
}
