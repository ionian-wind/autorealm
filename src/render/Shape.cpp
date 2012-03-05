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

#include <algorithm>

#include <GL/gl.h>

#include "Shape.h"
#include "Group.h"
#include "Line.h"

Shape Shape::split(Point<> const &beginBreak,Point<> const &endBreak)
{
//	insert(beginBreak);
//	insert(endBreak);
//	std::vector<Line>::iterator itBegin=
//		std::find(
//					m_children.begin(),
//					m_children.end(),
//					beginBreak);
//
//	std::vector<Line>::iterator itEnd=
//		std::find(
//					m_children.begin(),
//					m_children.end(),
//					endBreak);
//	if(itBegin==m_children.end() || itEnd==m_children.end())
//		throw std::runtime_error("Starting OR ending position are not in the given Shape");
//	Shape future(itBegin,itEnd);
//	m_children.erase(itBegin,itEnd);
//	return future;
}

void Shape::merge(Shape const & target)
{
//	m_children.insert(m_children.end(),target.m_children.begin(),target.m_children.end());
//	target.m_owner->erase(target);
}

void Shape::close(bool close)
{
	m_closed=close;
}

void Shape::insert(Line const & target)
{
	std::vector<Line>::iterator it=m_children.begin();
	while(!it->find(target) && it!=m_children.end())
		++it;
	if(it==m_children.end())
		throw std::runtime_error("Position not found in given Shape.");
	it->split(target);
}

void Shape::push_back(Line const & target)
{
	m_children.push_back(target);
}

void Shape::erase(Line const & target)
{
//	std::vector<Line>::iterator it=std::find(m_children.begin(),m_children.end(),target);
//	if(it==m_children.end())
//		throw std::runtime_error("Position not found in given Shape.");
//	m_children.erase(it);
}

Shape::Shape(std::vector<Line>::iterator const &begin,std::vector<Line>::iterator const &end)
//:m_children(begin,end)
{
}

void Shape::draw()
{
    if(m_children.size()<2)
        return;

    if(m_closed)
    {
        glColor4d(m_filler.m_red,m_filler.m_green,m_filler.m_blue,m_filler.m_alpha);
        glBegin(GL_POLYGON);
		drawShape(true);
        glBegin(GL_LINE_LOOP);
    }
    else
        glBegin(GL_LINE_STRIP);

	drawShape();
}

void Shape::move(const Point<> & distance)
{
	m_position+=distance;
}

void Shape::drawShape(bool ignoreColor)
{
//	glVertex3d(m_position.m_x,m_position.m_y,m_position.m_z);
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(std::bind1st(Line::lineDraw,ignoreColor)));
//	glEnd();
}

#warning untested implementation
