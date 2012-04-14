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

#include "toolbardata.h"

#include <wx/aui/auibar.h>

#include "../gui/appconfig.h"

ToolbarData::ToolbarData()
{
	//ctor
}

void ToolbarData::readFromFile(FILE * source)
{
//retrieve tool-bar item's informations
	m_longDoc=readline(source);
	std::string enabledPath(readline(source));
	std::string disabledPath(readline(source));

	//!\todo check for errors while opening bitmap files

	m_disabled=loadImage(disabledPath);
	m_enabled=loadImage(enabledPath);

	MenuData::readFromFile(source);
}

void ToolbarData::addTo(wxAuiToolBar* toolbar, long id)
{
	toolbar->AddTool(id, name, m_enabled, m_disabled, kind, name, m_longDoc, m_unused);
}
