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

#ifndef ITEM_H
#define ITEM_H

#include <memory>

#include "menuitem.h"

//class Plugin;
class Menu;

class Item : public MenuItem
{
friend class Menu;
public:
	virtual ~Item();
//	void associate(std::unique_ptr<Plugin> &target);
protected:
	Item(boost::filesystem::path const &location, Menu *parent);
private:

public:
protected:
//	std::unique_ptr<Plugin> m_plugin;
private:
};

#endif // ITEM_H
