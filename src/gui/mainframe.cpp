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

#include "renderwindow.h"
#include <tree.h>
#include "toolbaritemconfig.h"
#include <pluginEngine/pluginprovider.h>

#include "id.h"
#include "renderwindow.h"
#include "menuitemconfig.h"
#include "utils/utils.h"

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, std::string const &title)
: wxFrame(parent, id, title)
{
	m_auiManager.SetManagedWindow(this);
	m_auiNotebookWorkspace = new wxAuiNotebook(this);
	int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
	RenderWindow *first = new RenderWindow((wxFrame *)m_auiNotebookWorkspace, args );
	m_auiNotebookWorkspace->AddPage(first, "Map 1", true);
	m_plans.push_back(first);
	m_active = m_plans.begin();
	m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Center());

	//create menus
		m_actionPlugIn.acceptProviderType<PluginProvider>();
		//create the notebook and add it an empty page
		Node<MenuItemConfig> tmp2(createTree<MenuItemConfig>(AppConfig::buildPath(AppConfig::INFO::MENU)));
		loadRequestedPlugins(tmp2);
		SetMenuBar(createMenuFromFolder(tmp2));

	//create toolbars
		Node<ToolbarItemConfig> tmp(createTree<ToolbarItemConfig>(AppConfig::buildPath(AppConfig::INFO::TOOLBARS)));
		buildToolbars(m_auiManager,tmp);
		m_auiManager.Update();

	//enable default configuration
		getActive()->setDefaultRenderers();
}

MainFrame::~MainFrame(void)
{
	m_auiManager.UnInit();

//	for(std::pair<ID,Plugin*> i : m_plugins)
//		delete i.second;

	wxCommandEvent e;
	e.SetId(0);
	changeSelectedPlugin(e);
}

RenderWindow* MainFrame::getActive(void)const
{
	return *m_active;
}

void MainFrame::loadRequestedPlugins(Node<MenuItemConfig> &tree)
{
	for(Node<MenuItemConfig>::iterator it=tree.begin();it!=tree.end();++it)
	{
		if(it.isNode())
			loadRequestedPlugins(dynamic_cast<Node<MenuItemConfig>&>(*it));
		else
		{
			std::string plugName = it->get().plugin();
			if(plugName.empty())
				continue;
			AssocIDs::iterator jt = m_buttonIDs.find(plugName);

			if(jt == m_buttonIDs.end()) // plugin is not loaded? Try to load it.
			{
				assert(!m_actionPlugIn.isLoaded(plugName));///\note should never load twice the same plugin. Could be in pluma...
				PluginProvider *plugProvider = getProvider<PluginProvider>(m_actionPlugIn, AppConfig::buildPath(AppConfig::PLUGINS), plugName);

				if(nullptr != plugProvider)
				{
					ID tmpid(m_buttonIDs[plugName]);// avoid searching twice in the map
					Plugin* tmpplug=plugProvider->create(getActive());
					m_plugins[tmpid]=tmpplug;
					it->get().setId(tmpid);
				}
			}

			jt = m_buttonIDs.find(plugName);

			if(jt != m_buttonIDs.end()) // plugin loaded? Bind it.
				Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::changeSelectedPlugin, this, jt->second, jt->second);
		}
	}
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

void MainFrame::buildToolbars(wxAuiManager &mgr,Node<ToolbarItemConfig> & origin)
{
	for(auto it=origin.begin();it!=origin.end();++it)
	{
		if(it.isNode())
			mgr.AddPane(buildPaneComponents(dynamic_cast<Node<ToolbarItemConfig>&>(*it)),buildPaneInfo(*it));
		else
			throw std::runtime_error("root toolbar folder should only contain directories");
	}
	mgr.Update();
}


wxAuiToolBar* MainFrame::buildPaneComponents(Node<ToolbarItemConfig> &data)
{
	wxAuiToolBar *ret=new wxAuiToolBar(this);
	for(auto it=data.begin();it!=data.end();++it)
//		if(it.isNode())
			ret->AddTool(
				m_buttonIDs[it->get().plugin()],
				it->get().label(),
				wxBitmap(wxImage(AppConfig::buildPath(AppConfig::GRP_RES) +it->get().bmp())),
				it->get().desc(),
				static_cast<wxItemKind>(it->get().kind())
			);
//		else
//			throw std::runtime_error("toolbar children folders should only contain files");

	ret->Realize();
	return ret;
}
