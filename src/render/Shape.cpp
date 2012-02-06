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


#include "Shape.h"
#include "Line.h"
#include "Point.h"

#include <GL/gl.h>

Shape Shape::split()
{
}

void Shape::merge(const Shape & tarm_)
{
}

void Shape::close(bool close)
{
}

void Shape::createPoint(const Point & tarm_)
{
}

void Shape::addPoint(const Point & tarm_)
{
}

void Shape::removePoint(const Point & tarm_)
{
}

Shape::Shape(const Point & origin)
{
}

void Shape::draw()
{
	if(m_lines.size()<2)
		return;

	if(m_closed)
	{
		glColor4d(m_filler.m_red,m_filler.m_green,m_filler.m_blue,m_filler.m_alpha);
		glBegin(GL_POLYGON);
		for(int i=0;i<m_lines.size()-1;++i) //TODO (berenger#1#) use std::vector<Line>::size_t for better optimization
			m_lines[i].lineDraw(m_lines[i+1],true);
		glEnd();
		glBegin(GL_LINE_LOOP);
	}
	else
		glBegin(GL_LINE_STRIP);

	for(int i=0;i<m_lines.size()-1;++i) //TODO (berenger#1#) use std::vector<Line>::size_t for better optimization
		m_lines[i].lineDraw(m_lines[i+1]);
	glEnd();
}

