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

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>

#include <boost/filesystem.hpp>

#include "menuitem.h"
#include "iterator.h"

class Menu : public MenuItem
{
	typedef class Iterator<Menu> MenuIter;
	friend class Iterator<Menu>;
	typedef std::vector<std::unique_ptr<MenuItem>> Components;
public:
	Menu(boost::filesystem::path const &location);
	virtual ~Menu()=default;
	void buildMenu(boost::filesystem::path const &location);
	void create(void);
	MenuIter begin(void);
	MenuIter end(void);
protected:
	boost::filesystem::path findConfigurationFile(boost::filesystem::path const &location);
	virtual void create(MenuConverter* parent);
private:
public:
protected:
	Components m_components;
private:
};

#endif // MENU_H
