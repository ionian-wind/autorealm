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
#include <renderwindow.h>

#include <wx/menu.h>

Drawer::Drawer(void)
:m_menu(new wxMenu())
{
	m_menu->Append(m_menuIds[0], wxT("Create &Open Figure"));
	m_menu->Append(m_menuIds[1], wxT("Create &Closed Figure"));
	m_menu->AppendSeparator();
	m_menu->Append(m_menuIds[2], wxT("Suppress this menu and use &Shift for Closed Figures"));
}

Drawer::~Drawer(void)throw()
{
	delete m_menu;
	delete m_shape;
}

void Drawer::installEventManager(RenderWindow &target) throw()
{
	m_target = &target;

	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);
	m_target->Bind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::finalizeShape, this, m_menuIds[0], m_menuIds[1]);
}

void Drawer::removeEventManager(void) throw()
{
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::addPoint, this);
	m_target->Unbind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
	m_target->push_back(std::unique_ptr<Render::Shape>(m_shape));
	m_shape=nullptr;
}

void Drawer::firstPoint(wxMouseEvent &event)
{
	createShape();
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);
	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::secondPoint, this);
	addPoint(event);
}

void Drawer::secondPoint(wxMouseEvent &event)
{
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::secondPoint, this);
	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::addPoint, this);
	m_target->Bind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
	addPoint(event);
}

void Drawer::addPoint(wxMouseEvent &event)
{
	addVertex(Render::Point(event.GetX(),event.GetY(),0));
	render();
}

void Drawer::addVertex(Render::Point p)
{
	Render::Color c = m_target->getBorderColor(); ///\todo remove temp var
	m_shape->push_back(Render::Vertex(p, &c, clone()));
}

void Drawer::moveMouse(wxMouseEvent &event)
{
	Render::Shape s;
	Render::Color c=m_target->getBorderColor();
	s.setFiller(&c);
	s.push_back(Render::Vertex(m_shape->getLastChild()->getEnd(),&c,clone()));
	s.push_back(Render::Vertex(Render::Point(event.GetX(),event.GetY(),0),&c,clone()));

	render();
}

void Drawer::contextMenu(wxContextMenuEvent &event)
{
	wxPoint point = event.GetPosition();

	if(-1 == point.x && -1 == point.y) //from keyboard ?
	{
		assert(0);
		///\todo implement popup's menu's position when user use the context menu key
		//!\fixme it seem assert(0) is never executed. Guess that it is because I did not used the application pointer?
	}
	else
		point = m_target->ScreenToClient(point);

	m_target->PopupMenu(m_menu, point);
}

void Drawer::render(void)
{
	m_target->startRendering();
	m_shape->draw();
	m_target->draw();
	m_target->finalizeRendering();
}

void Drawer::finalizeShape(wxCommandEvent &event)
{
	if(event.GetId()==m_menuIds[1])//user asked for a closed shape
		m_shape->close();
	m_target->push_back(std::unique_ptr<Render::Shape>(m_shape));
	render();
	m_shape=nullptr;

	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::addPoint, this);
	m_target->Unbind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
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

void Drawer::createShape(void)
{
	assert(nullptr==m_shape);
	m_shape=new Render::Shape();
	Render::Color c(m_target->getFillerColor()); ///\todo remove temp var (and maybe references to Color?)
	m_shape->setFiller(&c);
}
