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

#include "shape.h"

#include <algorithm>

#include <GL/gl.h>

#include "vertex.h"

void Shape::accept(Mutator &v)
{
	//!\todo find a solution to use std::for_each
	v.visit(*this);
}

void Shape::draw(void)const
{
	glBegin(GL_LINE_STRIP);
	for(auto &i:m_children)
		i.render();
	glEnd();
	if(isClosed())
	{
		glBegin(GL_POLYGON);
		m_filler.apply();
		for(auto &i:m_children)
			i.render(&m_filler);
		glEnd();
	}
}

bool Shape::isClosed(void)const throw()
{
	if(m_children.empty())
		return false;
	return m_children.front()==m_children.back();
}

void Shape::push_back(Vertex const&target)
{
	m_children.push_back(target);
}

void Shape::setFiller(Color const&c)
{
	m_filler=c;
}

Color Shape::getFiller(void)const
{
	return m_filler;
}

std::vector<Vertex>::iterator Shape::getFirstChild(void)
{
	return m_children.begin();
}

std::vector<Vertex>::iterator Shape::getLastChild(void)
{
	return m_children.end();
}
