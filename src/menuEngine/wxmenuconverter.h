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

#ifndef WXMENUCONVERTER_H
#define WXMENUCONVERTER_H

#include <string>

class wxMenu;
class wxMenuBar;
class wxMenuItem;

class MenuConverter
{
public:
	virtual ~MenuConverter(){};
//	virtual ~MenuConverter()=default;
	operator wxMenuBar*(void)const;
protected:
	void init(MenuConverter *parent);
	virtual std::string getName(void)const=0;
	virtual std::string getHelp(void)const=0;
private:
private:
	union WWxContent
	{
		wxMenu* menu=nullptr;
		wxMenuBar* menubar;
		wxMenuItem* menuitem;
	}m_content;
	bool m_isMenuBar=false;
};

#endif // WXMENUCONVERTER_H
