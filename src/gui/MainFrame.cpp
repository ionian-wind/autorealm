/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU General Public License as published by        *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU General Public License for more details.                                *
 *                                                                                *
 *    You should have received a copy of the GNU General Public License           *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

#include "MainFrame.h"

#include <functional>
#include <algorithm>

#include <boost/filesystem.hpp>

#include "RenderWindow.h"
#include "id.h"
//#include <pluginEngine/container.h>

//!\todo move me in Pluma
template <class T>
T* getProvider(pluma::Pluma & plumConf, std::string const& location, std::string const& pluginName)
{
	std::vector<T*> prevProviders, actualProviders;
	plumConf.getProviders(prevProviders);
	if(plumConf.load(location,pluginName))
	{ // register loaded provider
		decltype(actualProviders.size()) i=0;
		plumConf.getProviders(actualProviders);//!\todo PlumaLack#1 remove that
		//!\todo PlumaLack#1 remove that
		//Locate the provider newly loaded
		while(i<actualProviders.size() && prevProviders.end()!=std::find(prevProviders.begin(),prevProviders.end(),actualProviders[i]))
			++i;

int j=i;int k=actualProviders.size();
		if(i<=actualProviders.size())
			return actualProviders[i];
	}
	return nullptr;
}

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
//,m_selected()
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

	//load only needed plugins
	auto at=m_menuTree.begin();
	auto bt=m_menuTree.end();
	for(auto it=m_menuTree.begin();it!=m_menuTree.end();++it)//only browse leaves
	{
		std::string plugName=it->getPluginName();
		auto jt=m_buttonIDs.find(plugName);
		if(jt==m_buttonIDs.end())// plugin is not loaded? Try to load it.
		{
			assert(!m_actionPlugIn.isLoaded(plugName));//!\note should never load twice the same plugin. Could be in pluma...
			PluginProvider* plugProvider=getProvider<PluginProvider>(m_actionPlugIn,AppConfig::buildPath(AppConfig::INFO::PLUGINS),plugName);
			if(nullptr==plugProvider)
				it->disable();
			else
				m_plugins[m_buttonIDs[plugName]].reset(plugProvider->create());
		}
		jt=m_buttonIDs.find(plugName);
		if(jt!=m_buttonIDs.end())// plugin loaded? Bind it.
		{
			Plugin *plu=m_plugins[jt->second].get();
			Bind(wxEVT_COMMAND_MENU_SELECTED,&Plugin::activator,plu, jt->second,jt->second);
		}
	}

	m_menuTree.create();
	SetMenuBar(m_menuTree.getMenuBar());

	m_auiManager.Update();
}

void MainFrame::onQuit(wxCommandEvent& event)
{
    Close();
}

//void MainFrame::changeLeftAction(wxCommandEvent& ev)
//{
//	static ITEM_CALLBACK s_actualCallback=0;
//	static Item *s_actualItem=0;
//
//	if(s_actualCallback)
//		(*m_active)->Unbind(wxEVT_LEFT_DOWN, s_actualCallback, s_actualItem);
//
////!\todo replace that with find_if
//	auto it=m_items.begin();
//	for(;it!=m_items.end();++it)
//		if((*it)->m_id==ev.GetId())
//			break;
//
////	auto it=std::find_if(m_items.begin(),m_items.end(),
////						std::bind2nd(std::mem_fun_ref<bool,Item,wxEvent&>(&Item::test),ev)
////						);
//
//	if(it==m_items.end())
//		throw std::runtime_error("item not found");
//	s_actualItem=&(**it);
//	s_actualCallback=s_actualItem->m_callback;
//	(*m_active)->Bind(wxEVT_LEFT_DOWN, s_actualCallback, s_actualItem);
//}
