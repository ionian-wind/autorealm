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

void Drawer::installEventManager(RenderWindow &target) throw()
{
	m_target=&target;
	m_target->push_back(std::unique_ptr<Shape>(new Shape()));
	m_target->selectLastObject();
	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
	m_target->Bind(wxEVT_RIGHT_DOWN, &Drawer::rightClick, this);
}

void Drawer::removeEventManager(void) throw()
{
	m_target->Unbind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
	m_target->Unbind(wxEVT_RIGHT_DOWN, &Drawer::rightClick, this);
	m_target=nullptr;
}

void Drawer::leftClick(wxMouseEvent &event)
{
	m_target->addVertex(event.GetX(),event.GetY(),clone());
}

void Drawer::rightClick(wxMouseEvent &event)
{
}

