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

#include "wxmenuconverter.h"

#include <wx/menu.h>
#include <wx/menuitem.h>

#include <utils/textfile.h>
#include <assert.h>

void MenuConverter::create(MenuConverter *parent, std::string const &title)
{
	///\todo find a way to check at compilation that (*this) is of the good type.
	//!\pre type of *this is Menu or Item
	assert(typeid(*this) == typeid(Composite<MenuConverter>) || typeid(*this) == typeid(Component<MenuConverter>)); //, "(*this)'s type can only be Menu or Item");
	//!\pre parent must be a Menu
	assert(parent == nullptr || typeid(*parent) == typeid(Composite<MenuConverter>)); //, "(*parent)'s type can only be Menu");
	//!\pre Item can not be added to a menubar
	assert(typeid(*this) == typeid(Composite<MenuConverter>) || (parent != nullptr && false == parent->m_isMenuBar)); //, "Item can not be added to a root Menu (aka: menubar. WxWidget's limitation)");

	m_isMenuBar = false; ///\todo this flag should have been set at constructor. Why is it not?

	if(nullptr == parent)
	{
		m_content.menubar = new wxMenuBar();
		m_isMenuBar = true;
	}
	else
	{
		//create Menu or Item
		if(typeid(*this) == typeid(Composite<MenuConverter>))
			m_content.menu = new wxMenu(title); ///\todo implement style
		else
		{
			m_content.menuitem = new wxMenuItem(parent->m_content.menu, m_id, title, getHelp(), wxITEM_NORMAL);
			//m_content.menuitem->Enable(isEnabled());
			///\todo find a solution to indicate that a meu item is useless
		}

		if(parent->m_isMenuBar)
			parent->m_content.menubar->Append(m_content.menu, title);// it is only possible to add menu to menubars
		else
		{
			if(typeid(*this) == typeid(Composite<MenuConverter>))
				parent->m_content.menu->AppendSubMenu(m_content.menu, title, getHelp());
			else
				parent->m_content.menu->Append(m_content.menuitem);
		}

	}
}

wxMenuBar *MenuConverter::getMenuBar(void)const
{
	assert(typeid(*this) == typeid(Composite<MenuConverter>) && true == m_isMenuBar);
	return m_content.menubar;
}

std::string MenuConverter::getHelp(void)const
{
	return m_help;
}

void MenuConverter::loadConfiguration(TextFile &file)
{
	m_help = file.readLine();
}

void MenuConverter::setID(uint16_t id)
{
	m_id = id;
}
