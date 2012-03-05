/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel B�renger                                               *
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

#ifndef _TOOLBARITEM_H
#define _TOOLBARITEM_H


#include <string>
#include <wx/pen.h>
#include <wx/bitmap.h>
#include <wx/sizer.h>
#include <wx/aui/auibar.h>


class ToolBar;

class ToolbarItem
{
private:
    std::string m_name;

    unsigned short m_id;

    ToolBar * m_container;

    wxAuiToolBarItem m_wxData;


public:
    void registerIn(const ToolBar & tb);


};
#endif
