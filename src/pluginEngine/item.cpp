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

Item::Item(std::string const& cfgFileName)
:m_configFileName(cfgFileName),m_id(wxNewId()),m_callback(NULL)
{
}

wxImage Item::loadImage(std::string const & fileName,AppConfig const& config)const
{
	if(fileName.empty())
		return wxNullBitmap;
	return config.m_graphicalResources+disabledPath;
}

void Item::readConfig(AppConfig const& config)
{
//!\todo check the portability of this method
//!\todo think about a configuration written in a pseudo file-system. Something like Menu<=>directory and Item<=>file
	FILE *input=0;
	std::string configFileFullPath=config.m_configfiles+config.m_pluginsConfig+m_configFileName;
	input=fopen(configFileFullPath.c_str(),"r");
	if(!input)
		throw std::runtime_error("can not open the file "+configFileFullPath);//!\todo write config and retry to read configuration before leaving

	readConfig(config,input);

//retrieve tool-bar item's informations
	m_longDoc=readline(input);
	std::string enabledPath(readline(input));
	std::string disabledPath(readline(input));

	//!\todo check for errors while opening bitmap files

	m_disabled=loadImage(disabledPath,config);
	m_enabled=loadImage(enabledPath,config);

	//retrieve all path entries
	MenuData entry;
	do
	{
		try
		{
			entry.readFromFile(input);
		}catch(std::runtime_error &e)
		{
			throw e;
		}
		m_path.push_back(entry);
	}while(!eofReached(input));

	//take the last entry to put it in m_entry, and remove it from the path
	m_entry=m_path.back();
	m_path.pop_back();
	if(m_path.empty())
		throw std::runtime_error("configuration file corrupted");
	fclose(input);
}

void Item::registerIn(MainFrame *parent,std::map<std::string,Container>&containers,AppConfig const& appConfig)
{
	m_parent=parent;

	readConfig(appConfig);
	createMenu();
	createToolbarItem(containers);
}

void Item::createToolbarItem(std::map<std::string,Container>&containers)
{
	std::map<std::string,Container>::iterator it=containers.find(m_path.back().name);
	if(it==containers.end())
	{
		//create & register container
		Container c;
		c.first=new wxAuiToolBar(m_parent);
		c.second=wxAuiPaneInfo().Name(m_path.rbegin()->name).ToolbarPane().Caption(m_path.rbegin()->name).Layer(10).Top().Gripper();
		containers[m_path.back().name]=c;
	}

	wxAuiToolBar* toolbar=containers[m_path.back().name].first;
	wxAuiPaneInfo paneInfo=containers[m_path.back().name].second;

	//create the item
	toolbar->AddTool(m_id, m_entry.name, m_enabled, m_disabled, m_entry.kind, m_entry.name, m_longDoc, m_unused);
}

void Item::createMenu(void)
{
	wxMenuBar *menubar=m_parent->GetMenuBar();
	wxMenu *menuitem;
	std::vector<MenuData>::iterator it=m_path.begin();
	int id;

	if(m_path.empty())
		throw std::runtime_error("Empty path are not allowed");

	//retrieve the id of the first menu if existing
	id=menubar->FindMenu(it->name);
	if(wxNOT_FOUND!=id) // found it? Find the last corresponding child
	{
		menuitem=GetMenu(id);
		menuitem=findLastMenu(menuitem,it);
	}
	else // not found? Create it and get the new menu
	{
		menubar->Append(new wxMenu(),it->name);
		id=menubar->FindMenu(it->name);
		if(wxNOT_FOUND==id)
			throw std::runtime_error("Can not find the menu with FindMenu, but we just create it!");
		menuitem=GetMenu(id);
	}
	// now create all sub-menus
	menuitem=createMenuPath(menuitem,it);
	// finish by creating the menu item itself
	menuitem->Append(new wxMenuItem(menuitem,m_id,m_entry.name,m_entry.help,m_entry.kind));
}

wxMenu *Item::GetMenu(int id)
{
	wxMenu *menu=m_parent->GetMenuBar()->GetMenu(id);
	if(NULL==menu)
		throw std::runtime_error("FindMenu gives something but GetMenu failed!");
	return menu;
}

wxMenu* Item::findLastMenu(wxMenu *parent,std::vector<MenuData>::iterator &it)
{
	while(parent->FindItem((++it)->name)&&it!=m_path.end())
	{
	}
	--it;
	long id=parent->FindItem(it->name);
	if(wxNOT_FOUND!=id)
	{
		++it;
		parent=parent->FindItem(id)->GetSubMenu();
	}
	--it;
	return parent;
}

wxMenu *Item::createMenuPath(wxMenu *parent,std::vector<MenuData>::iterator &it)
{
	++it;
	if(m_path.end()==it)
		return parent;

	wxMenu *newMenu=new wxMenu();
	parent->AppendSubMenu(newMenu,it->name);
	return createMenuPath(newMenu,it);
}

PLUMA_PROVIDER_SOURCE(Item,1,1)
