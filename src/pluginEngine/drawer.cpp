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
#include <id.h>

#include <wx/menu.h>

const int Menu_Popup_OpenFig = ID(); //!todo remove global variables
const int Menu_Popup_CloseFig = ID(); //!todo remove global variables
const int Menu_Popup_UseShift = ID(); //!todo remove global variables

void Drawer::installEventManager(RenderWindow &target) throw()
{
	m_target=&target;

	//!\todo that code could be merged with a part of createOpenedFigure
	m_shape.reset(new Shape());
	m_shape->setFiller(m_target->getFillerColor());//!\todo remove me

	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
	m_target->Bind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);

	m_target->Bind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::createOpenedFigure, this, Menu_Popup_OpenFig, Menu_Popup_OpenFig);
	m_target->Bind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::createClosedFigure, this, Menu_Popup_CloseFig, Menu_Popup_CloseFig);
}

void Drawer::createOpenedFigure(wxCommandEvent &event)
{
	m_target->push_back(std::move(m_shape));
	//!\todo that code could be merged with a part of installEventManager
	m_shape.reset(new Shape());
	m_shape->setFiller(m_target->getFillerColor());//!\todo remove me
	render();
}

void Drawer::createClosedFigure(wxCommandEvent &event)
{
	m_shape->close();
	createOpenedFigure(event);
}

void Drawer::removeEventManager(void) throw()
{
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
	m_target->Unbind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
	m_target=nullptr;
	m_target->push_back(std::move(m_shape));
	m_shape.reset();
}

void Drawer::leftClick(wxMouseEvent &event)
{
	m_lastClick.m_x=event.GetX();
	m_lastClick.m_y=event.GetY();
	m_lastClick.m_z=0;
	m_shape->push_back(Vertex(m_lastClick,m_target->getBorderColor(),clone()));
	render();
}

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

void Drawer::closer(wxCommandEvent &event)
{
	m_shape->close();
	adder(event);
}

void Drawer::adder(wxCommandEvent &event)
{
	removeEventManager();
	render();
}

void Drawer::shifter(wxCommandEvent &event)
{
}

void Drawer::render(void)
{
	m_target->startRendering();
	m_shape->draw();
	m_target->draw();
	m_target->finalizeRendering();
}
