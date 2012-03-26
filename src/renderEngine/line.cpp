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

#include "line.h"

#include "visitor.h"

Line::Line(void)
:m_color(),m_end()
{
}

Line::Line(Point const &end, Color const &color)
:m_color(color),m_end(end)
{
}

Line::Line(Line const&other)
:m_color(other.m_color),m_end(other.m_end)
{
	m_color=other.m_color;
	m_end=other.m_end;
}

//void Line::accept(Visitor &v)
//{
//	v.visit(*this);
//}
void Line::draw(void)const
{
	m_end.createVertice();
}

Color Line::getColor(void)
{
	return m_color;
}

Point Line::getEnd(void)
{
	return m_end;
}

void Line::setColor(Color &c)
{
	m_color=c;
}

void Line::setEnd(Point &p)
{
	m_end=p;
}
