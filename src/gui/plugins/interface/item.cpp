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

#include "../../appconfig.h"

Item::Item(void)
:m_id(wxNewId())
{}

void Item::registerIn(wxFrame *parent,std::map<std::string,Container>&containers,AppConfig const& appConfig)
{
	readConfig(appConfig.m_graphicalResources);

	createMenu(parent);
	createToolbarItem(containers,parent);
}

void Item::createMenu(wxFrame *parent)
{
	wxMenu *target=NULL;
	wxMenuBar *menubar=parent->GetMenuBar();
	int targetIndex;

//ensure the existency of the menu path
//FIXME initialize target before searching or the appli will crash!!!
	std::vector<MenuData>::iterator it=m_path.begin();
	if(wxNOT_FOUND==(targetIndex=menubar->FindMenu(it->name)))
	{
		menubar->Append(new wxMenu(),it->name);
		targetIndex=menubar->FindMenu(it->name);
		if(wxNOT_FOUND==targetIndex)
			throw std::runtime_error(wxString("unable to create menu: ")+it->name);
	}
	target=menubar->GetMenu(targetIndex);
	++it;

	for(;it!=m_path.end();++it)
	{
		if(wxNOT_FOUND==(targetIndex=target->FindItem(it->name)))
		{
			// create all submenus
			for(;it!=m_path.end();++it)
			{
				target->Append(
								new wxMenuItem(
												target,
												wxNewId(),
												it->name,
												it->help,
												it->kind,
												target
												)
								);
				targetIndex=target->FindItem(it->name);
				if(wxNOT_FOUND==targetIndex)
					throw std::runtime_error(wxString("unable to create menu: ")+it->name);
				target=menubar->GetMenu(targetIndex);
			}
		}
		target=menubar->GetMenu(targetIndex);
	}
	//create menu item
	wxMenuItem *tmp=new wxMenuItem(target,m_id,m_entry.name,m_entry.help,m_entry.kind,0);
	target->Append(tmp);
}

void Item::createToolbarItem(std::map<std::string,Container>&containers,wxWindow *parent)
{
	std::map<std::string,Container>::iterator it=containers.find(m_entry.name);
	if(it==containers.end())
	{
		//create & register container
		Container c;
		c.first=new wxAuiToolBar(parent);
		c.second=wxAuiPaneInfo().Name(m_path.rbegin()->name).ToolbarPane().Caption(m_path.rbegin()->name).Layer(10).Top().Gripper();
		containers[m_entry.name]=c;
	}
	//create the item
	containers[m_entry.name].first->AddTool(wxNewId(), m_entry.name, m_enabled, m_disabled, m_entry.kind, m_entry.name, m_longDoc, m_unused);

	//insert the item inside the container
	wxAuiManager::GetManager(parent)->AddPane(containers[m_entry.name].first,containers[m_entry.name].second);
}

PLUMA_PROVIDER_SOURCE(Item,1,1)
