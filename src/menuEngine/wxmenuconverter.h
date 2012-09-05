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

#ifndef WXMENUCONVERTER_H
#define WXMENUCONVERTER_H

#include <string>

class wxMenu;
class wxMenuBar;
class wxMenuItem;
class TextFile;

#include "composite.h"

class MenuConverter
{
	friend class Composite<MenuConverter>; ///\todo find why this declaration is needed and correct the problem!
public:
	virtual ~MenuConverter()throw();
	wxMenuBar *getMenuBar(void)const;
	virtual bool isEnabled(void)const = 0;
	void setID(uint16_t id);
protected:
	virtual void loadConfiguration(TextFile &file);
	virtual void create(MenuConverter *parent, std::string const &title);
	virtual std::string getName(void)const = 0;
	virtual std::string getHelp(void)const;
private:
private:
	union WWxContent
	{
		wxMenu *menu = nullptr;
		wxMenuBar *menubar;
		wxMenuItem *menuitem;
	} m_content;
	bool m_isMenuBar = false;
	std::string m_help;
	uint16_t m_id = 0;
};

#endif // WXMENUCONVERTER_H
