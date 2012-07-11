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

#include "drawer.h"

#include <shape.h>
#include <RenderWindow.h>

#include <wx/menu.h>

void Drawer::installEventManager(RenderWindow &target) throw()
{
	m_target=&target;
	m_target->push_back(std::unique_ptr<Shape>(new Shape()));
	m_target->selectLastObject();
	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
	m_target->Bind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
}

void Drawer::removeEventManager(void) throw()
{
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
	m_target->Unbind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
	m_target=nullptr;
}

void Drawer::leftClick(wxMouseEvent &event)
{
	m_target->addVertex(event.GetX(),event.GetY(),clone());
}

enum
{
    Menu_Popup_OpenFig = 2000,
    Menu_Popup_CloseFig,
    Menu_Popup_UseShift
};

void Drawer::contextMenu(wxContextMenuEvent &event)
{
	wxPoint point=event.GetPosition();
	if(-1==point.x && -1==point.y) //from keyboard ?
	{
		assert(0);
		//!\todo implement popup's menu's position when user use the context menu key
		//!\fixme it seem assert(0) is never executed. Guess that it is because I did not used the application pointer?
	}
	else
		point=m_target->ScreenToClient(point);

    wxMenu menu;

	menu.Append(Menu_Popup_OpenFig, wxT("Create &Open Figure"));
	menu.Append(Menu_Popup_CloseFig, wxT("Create &Closed Figure"));
	menu.AppendSeparator();
	menu.Append(Menu_Popup_UseShift,wxT("Suppress this menu and use &Shift for Closed Figures"));

	m_target->PopupMenu(&menu, point);
}
