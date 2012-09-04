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

#include <renderEngine/shape.h>
#include <gui/renderwindow.h>

#include <wx/menu.h>

#include "graphicprimitive.h"

ID Drawer::m_menuIds[3];
wxMenu *Drawer::m_menu(nullptr);

Drawer::Drawer(RenderWindow *window)
:Plugin(window)
{
	if(!m_menu)
	{
		m_menu=new wxMenu();

		m_menu->Append(m_menuIds[0], wxT("Create &Open Figure"));
		m_menu->Append(m_menuIds[1], wxT("Create &Closed Figure"));
		m_menu->AppendSeparator();
		m_menu->Append(m_menuIds[2], wxT("Suppress this menu and use &Shift for Closed Figures"));
	}
}

Drawer::Drawer(Drawer const& other)
:Plugin(other),m_shape(dynamic_cast<Render::Shape*>(other.m_shape->clone())),m_shape1stPoint(other.m_shape1stPoint)
{
}

Drawer::~Drawer(void)throw()
{
	removeEventManager();
}

void Drawer::installEventManager(void) throw()
{
	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);
	m_target->Bind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::finalizeShape, this, m_menuIds[0], m_menuIds[1]);
}

void Drawer::removeEventManager(void) throw()
{
	if(nullptr==m_shape)

		m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);
	else
	{
		m_target->Unbind(wxEVT_MOTION, &Drawer::moveMouse, this);
		if(m_shape1stPoint)
			m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::secondPoint, this);
		else
			m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::addPoint, this);
			m_target->Unbind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
		m_shape1stPoint=false;
		delete m_shape;// really useful? I do not think so
	}
	m_target->Unbind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::finalizeShape, this, m_menuIds[0], m_menuIds[1]);
}

void Drawer::firstPoint(wxMouseEvent &event)
{
	createShape();
	addVertex(Render::Point(event.GetX(),event.GetY(),0));
	addPoint(event);

	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);
	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::secondPoint, this);
	m_target->Bind(wxEVT_MOTION, &Drawer::moveMouse, this);//when a shape have a point, draw a line between it and the cursor

	m_shape1stPoint=true;
}

void Drawer::secondPoint(wxMouseEvent &event)
{
	m_shape1stPoint=false;
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
	Render::Vertex *v(new Render::Vertex());
	v->setEnd(p);
	v->setDrawer(*this);
	m_shape->push(*v);
}

void Drawer::finalizeShape(wxCommandEvent &event)
{
	m_shape->pop();
	if(event.GetId()==m_menuIds[1])//user asked for a closed shape
		m_shape->close();
	m_target->push_back(m_shape);
	render();
	m_shape=nullptr;

	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::firstPoint, this);

	m_target->Unbind(wxEVT_MOTION, &Drawer::moveMouse, this);
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::addPoint, this);
	m_target->Unbind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
}

void Drawer::moveMouse(wxMouseEvent &event)
{
	m_shape->pop();
	addPoint(event);
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

void Drawer::createShape(void)
{
	assert(nullptr==m_shape);
	m_shape=new Render::Shape();
	m_shape->setFiller(m_target->getFillerColor());
}
