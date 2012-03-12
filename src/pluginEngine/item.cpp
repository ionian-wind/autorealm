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
#include "item.h"

#include "container.h"

#include <stdexcept>

#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/menu.h>

#include "../gui/appconfig.h"
#include "../gui/MainFrame.h"

Item::Item(void)
:m_id(wxNewId()),m_callback(NULL)
{
}

void Item::readConfig(std::string const & graphicalResources)
{
	m_entry.help="help about polylinetool";
	m_entry.kind=wxITEM_NORMAL;
	m_entry.name="polylinetool";
	m_id=wxNewId();

	m_path.push_back(MenuData("Tool","tool menu",wxITEM_NORMAL));
	m_path.push_back(MenuData("azerty","lkjhgfsdfghjkl",wxITEM_NORMAL));
	m_path.push_back(MenuData("hgfdsq","wxcvbn,;;bcx",wxITEM_NORMAL));

	m_longDoc="long doc about polylinetool";
	m_disabled=wxNullBitmap;
	m_enabled=wxImage(graphicalResources+"png_files/toolbars/shape/tool-polycurve.png");

}

void Item::registerIn(MainFrame *parent,std::map<std::string,Container>&containers,AppConfig const& appConfig)
{
	m_parent=(wxFrame*)parent;
//	readConfig(appConfig.m_graphicalResources);
	m_entry.help="help about polylinetool";
	m_entry.kind=wxITEM_NORMAL;
	m_entry.name="polylinetool";
	m_id=wxNewId();

	m_path.push_back(MenuData("Tool","tool menu",wxITEM_NORMAL));
	m_path.push_back(MenuData("azerty","lkjhgfsdfghjkl",wxITEM_NORMAL));
	m_path.push_back(MenuData("hgfdsq","wxcvbn,;;bcx",wxITEM_NORMAL));

	m_longDoc="long doc about polylinetool";
	m_disabled=wxNullBitmap;
	m_enabled=wxImage(appConfig.m_graphicalResources+"png_files/toolbars/shape/tool-polycurve.png");


	createMenu();
	createToolbarItem(containers);
	enable();
}

void Item::createToolbarItem(std::map<std::string,Container>&containers)
{
	std::map<std::string,Container>::iterator it=containers.find(m_entry.name);
	if(it==containers.end())
	{
		//create & register container
		Container c;
		c.first=new wxAuiToolBar(m_parent);
		c.second=wxAuiPaneInfo().Name(m_path.rbegin()->name).ToolbarPane().Caption(m_path.rbegin()->name).Layer(10).Top().Gripper();
		containers[m_entry.name]=c;
	}
	//create the item
	containers[m_entry.name].first->AddTool(m_id, m_entry.name, m_enabled, m_disabled, m_entry.kind, m_entry.name, m_longDoc, m_unused);

	//insert the item inside the container
	wxAuiManager::GetManager(m_parent)->AddPane(containers[m_entry.name].first,containers[m_entry.name].second);
}

void Item::createMenu(void)
{
	wxMenuBar *menubar=m_parent->GetMenuBar();
	wxMenu *menuitem;
	wxMenu *menu;
	std::vector<MenuData>::iterator it=m_path.begin();
	int id;

	if(m_path.empty())
		throw std::runtime_error("Empty path are not allowed");

	//retrieve the id of the first menu if existing
	id=menubar->FindMenu(it->name);
	if(wxNOT_FOUND!=id) // found it? Find the last corresponding child
	{
		menuitem=menubar->GetMenu(id);
		if(NULL==menuitem)
			throw std::runtime_error("FindMenu gives something but GetMenu failed!");
		menuitem=findLastMenu(menuitem,it);
	}
	else // not found? Create it and get the new menu
	{
		menubar->Append(new wxMenu(),it->name);
		id=menubar->FindMenu(it->name);
		if(wxNOT_FOUND==id)
			throw std::runtime_error("Can not find the menu with FindMenu, but we just create it!");
		menuitem=menubar->GetMenu(id);
		if(NULL==menuitem)
			throw std::runtime_error("FindMenu gives something but GetMenu failed!");
	}
	// now create all sub-menus
	menu=createMenuPath(menuitem,it);
	// finish by creating the menu item itself
	menu->Append(new wxMenuItem(0,m_id,m_entry.name,m_entry.help,m_entry.kind,0));
}

wxMenu* Item::findLastMenu(wxMenu *parent,std::vector<MenuData>::iterator &it)
{
	{
		wxMenu *submenu;
		wxMenuBar *menubar=m_parent->GetMenuBar();
		long id;
		id=menubar->FindMenu(it->name);
		if(wxNOT_FOUND==id)
			return parent;
		submenu=menubar->GetMenu(id);
		if(NULL==submenu)
			throw std::logic_error("error when trying to get the menu (which was found)");
		parent=submenu;
	}
	++it;
	return findLastMenu(parent,it);
}

wxMenu *Item::createMenuPath(wxMenu *parent,std::vector<MenuData>::iterator &it)
{
	wxMenu *newMenu=new wxMenu();
	++it;
	if(m_path.end()==it)
		return newMenu;

	parent->AppendSubMenu(newMenu,it->name);
	return createMenuPath(newMenu,it);
}

void Item::enable(void)
{
	m_parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &Item::DumbMethod, this, m_id);
}

void Item::DumbMethod(wxCommandEvent& event)
{
	wxMessageBox("hello world","hello caption");
}
PLUMA_PROVIDER_SOURCE(Item,1,1)
