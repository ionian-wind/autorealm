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

#include "drawer.h"

#include <GL/gl.h>

#include "line.h"
#include "shape.h"
#include "group.h"

void Drawer::visit(Group& v)
{
//	for(Group::CHILDLIST::iterator it=v.children().begin();it!=v.children().end();++it)
//		(*it)->accept(*this);
}

void Drawer::visit(Shape& v)
{
	glBegin(GL_LINE_LOOP);
	v.getFiller().apply();
	v.getStart().createVertice();
	for(Shape::CHILDLIST::iterator it=v.children().begin();it!=v.children().end();++it)
		(*it)->accept(*this);
	glEnd();
}

void Drawer::visit(Line& v)
{
	v.getColor().apply();
	v.getEnd().createVertice();
}
