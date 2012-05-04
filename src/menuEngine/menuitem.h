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
//#include <boost/filesystem.hpp>

#include "wxmenuconverter.h"

class IComponent: public MenuConverter
{
	public:
		std::string getPluginName(void)const;
		virtual ~IComponent()=default;
		std::string getName(void)const;
		void disable(bool disable=true);
		bool isEnabled(void)const;
		bool m_isComposite=false; //!\todo remove this horror as soon as possible!
	protected:
		void virtual loadConfiguration(std::unique_ptr<TextFile> &file);
		//void init(boost::filesystem::path const &file);
	private:
		std::string m_name;
		bool m_enable=true;
};

#endif // MENUITEM_H
