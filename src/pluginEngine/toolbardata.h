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

#ifndef TOOLBARDATA_H
#define TOOLBARDATA_H

#include "menudata.h"

class wxAuiToolBar;

class ToolbarData : public MenuData
{
public:
protected:
	std::string m_longDoc;
	wxObject *m_unused;
	wxBitmap m_disabled,m_enabled;

public:
	ToolbarData();
	virtual void readFromFile(std::unique_ptr<TextFile> &source);
	void addTo(wxAuiToolBar* toolbar, long id);
protected:
private:
};

#endif // TOOLBARDATA_H
