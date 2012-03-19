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

#include <algorithm>

#include <GL/gl.h>

#include "Shape.h"
#include "Group.h"
#include "Line.h"

Shape Shape::split(Point<> const &beginBreak,Point<> const &endBreak)
{
//	insert(beginBreak);
//	insert(endBreak);
//	Children::iterator itBegin=
//		std::find(
//					m_children.begin(),
//					m_children.end(),
//					beginBreak);
//
//	Children::iterator itEnd=
//		std::find(
//					m_children.begin(),
//					m_children.end(),
//					endBreak);
//	if(itBegin==m_children.end() || itEnd==m_children.end())
//		throw std::runtime_error("Starting OR ending position are not in the given Shape");
//	Shape future(itBegin,itEnd);
//	m_children.erase(itBegin,itEnd);
//	return future;
	UNIMPLEMENTED;
}

void Shape::merge(Shape *target)
{
	m_children.insert(m_children.end(),target->m_children.begin(),target->m_children.end());
	target->m_owner->erase(target);
}

void Shape::close(bool close)
{
	m_closed=close;
}

void Shape::insert(Line const& target)
{
	Children::iterator it=m_children.begin();
	while(!static_cast<Line*>(*it)->find(target) && it!=m_children.end())
		++it;
	if(it==m_children.end())
		throw std::runtime_error("Position not found in given Shape.");
	static_cast<Line*>(*it)->split(target);
}

void Shape::push_back(Line const& target)
{
	m_children.push_back(new Line(target));
}

void Shape::erase(Line const& target)
{
//	Children::iterator it=std::find(m_children.begin(),m_children.end(),target);
//	if(it==m_children.end())
//		throw std::runtime_error("Position not found in given Shape.");
//	m_children.erase(it);
	UNIMPLEMENTED;
}

Shape::Shape(std::vector<Line*>::iterator const &begin,std::vector<Line*>::iterator const &end)
//:m_children(begin,end)
{
	UNIMPLEMENTED;
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

void Shape::drawShape(bool ignoreColor)
{
//	glVertex3d(m_position.m_x,m_position.m_y,m_position.m_z);
////	for_each(m_children.begin(),
////			m_children.end(),
////			std::mem_fun(std::bind1st(Line::lineDraw,ignoreColor)));
//	for(Children::iterator it=m_children.begin();it!=m_children.end();++it)
//		static_cast<Line>(*it).lineDraw(ignoreColor);
//	glEnd();
	UNIMPLEMENTED;
}

void Shape::move(const Point<> & distance)
{
	m_position+=distance;
}

void Shape::rotate(short degree)
{
}

void Shape::rotate(float radian)
{
}

void Shape::resize(uint8_t width, uint8_t height)
{
}

#warning untested implementation
