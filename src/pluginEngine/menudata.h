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

#ifndef MENU_DATA_H
#define MENU_DATA_H

#include <string>
#include <stdexcept>

#include <wx/frame.h>
#include "../utils/utils.h"

class MenuData
{
public:
	static const long NOT_FOUND=-1;
protected:
	wxItemKind kind;
	std::string help;
	std::string name;
private:
	std::string m_corruptedFile;

public:
	std::string const &getName(void)const{return name;}
	MenuData(std::string const &nAME, std::string const& hELP, wxItemKind const kIND);
	MenuData(void);
	virtual void readFromFile(FILE * source);
	long findIn(wxMenu *parent)const;
	long findIn(wxMenuBar *parent)const;
	bool exist(wxMenu *parent)const;
	wxMenuItem* addTo(wxMenu *parent,long id)const;
	wxMenu* addTo(wxMenu *parent)const;
	wxMenu* addTo(wxMenuBar *parent)const;

protected:
	void checkName(void);
private:
};

#endif
