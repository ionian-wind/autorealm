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

#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <boost/filesystem.hpp>

#include "wxmenuconverter.h"

class MenuItem: public MenuConverter
{
	public:
		virtual ~MenuItem()=default;
		std::string getName(void)const{return m_name;}
		std::string getHelp(void)const{return m_help;}
	protected:
		void init(boost::filesystem::path const &file, MenuItem *parent);
	private:
		std::string m_name;
		std::string m_help;
};

#endif // MENUITEM_H
