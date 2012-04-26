/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel B�renger                                               *
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
//#include <pluginEngine/container.h>

const long MainFrame::ID_NOTEBOOK = wxNewId();
const long MainFrame::ID_MENUQUIT = wxNewId();

MainFrame::~MainFrame(void)
{
//	for(auto &i:m_items)//!\todo find a way to let unique_ptr<> do the delete job when destroyed by vector's destruction
//		i.reset();

	m_auiManager.UnInit();
}

MainFrame::MainFrame(wxWindow *parent,wxWindowID id,std::string const &title)
:wxFrame(parent,id,title)
,m(boost::filesystem::path(AppConfig::buildPath(AppConfig::INFO::MENU)))
{
    wxMenu* MenuFile;
    wxMenuItem* MenuItemExit;

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

	SetMenuBar(m.getMenuBar());
////add menu entry File->Exit
//    m_MenuBar = new wxMenuBar();
//	SetMenuBar(m_MenuBar);
//
//    MenuFile = new wxMenu();
//    m_MenuBar->Append(MenuFile, _("&File"));
//    MenuItemExit = new wxMenuItem(MenuFile, ID_MENUQUIT, _("&Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
//    MenuFile->Append(MenuItemExit);
//	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::onQuit, this, ID_MENUQUIT);
//
////add all plug-ins entries
//	m_actionPlugIn.acceptProviderType<ItemProvider>();
//	m_actionPlugIn.loadFromFolder("plugin");
//	m_actionPlugIn.getProviders(m_actionProviders);
//
//	m_items.reserve(m_actionProviders.size());
//	std::transform(m_actionProviders.begin(),m_actionProviders.end(),std::inserter(m_items,m_items.begin()),
//					[](ItemProvider *ita)
//					{return std::unique_ptr<Item>(ita->create());});
//
//	//!\todo use algorithms (for_each and transform) instead of for loops
//	for(auto &i:m_items)
//		registerItem(i);
//
//	for(auto p:m_containers)
//		m_auiManager.AddPane(p.second.first,p.second.second);

	m_auiManager.Update();
}

//void MainFrame::registerItem(std::unique_ptr<Item> &item)
//{
//	auto id=item->m_id;
//	item->readConfig();
//	wxMenu *lastMenu=item->createMenu(this);
////TODO make this function doing something
//	std::string name=item->m_path.back().getName();
//
//	if(m_containers.find(name)==m_containers.end())
//		m_containers[name].createToolbar(name,this);
//
//	m_containers[name].createItem(item->m_toolbarItem,id);
//	static_cast<MenuData>(item->m_toolbarItem).addTo(lastMenu, id);
//
//	Bind(wxEVT_COMMAND_MENU_SELECTED,&MainFrame::changeLeftAction,this,id,id);
//}

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
