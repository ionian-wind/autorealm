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

#include "wxmenuconverter.h"

#include <wx/menu.h>
#include <wx/menuitem.h>

#include "item.h"
#include "menu.h"
#include "menuitem.h"

#include <assert.h>

void MenuConverter::init(MenuConverter *parent)
{
	//!\todo find a way to check at compilation that (*this) is of the good type.
	//!\pre type of *this is Menu or Item
	assert(typeid(*this)==typeid(Menu) || typeid(*this)==typeid(Item));//, "(*this)'s type can only be Menu or Item");
	//!\pre parent must be a Menu
	assert(parent==nullptr || typeid(*parent)==typeid(Menu));//, "(*parent)'s type can only be Menu");
	//!\pre Item can not be added to a menubar
	assert(typeid(*this)==typeid(Menu) || (parent!=nullptr && false==parent->m_isMenuBar));//, "Item can not be added to a root Menu (aka: menubar. WxWidget's limitation)");

	if(nullptr==parent)
	{
		m_content.menubar=new wxMenuBar();
		m_isMenuBar=true;
	}
	else
	{
		//create Menu or Item
		if(typeid(*this)==typeid(Menu))
			m_content.menu=new wxMenu(getName()); //!\todo implement style
		else
			m_content.menuitem=new wxMenuItem(parent->m_content.menu, wxNewId(),getName(),getHelp(),wxITEM_NORMAL);

		if(parent->m_isMenuBar)
			parent->m_content.menubar->Append(m_content.menu, getName());// it is only possible to add menu to menubars
		else
		{
			if(typeid(*this)==typeid(Menu))
				parent->m_content.menu->AppendSubMenu(m_content.menu,getName(),getHelp());
			else
				parent->m_content.menu->Append(m_content.menuitem);
		}

	}
}

wxMenuBar* MenuConverter::getMenuBar(void)const
{
	assert(typeid(*this)==typeid(Menu) && m_isMenuBar==true);
	return m_content.menubar;
}
