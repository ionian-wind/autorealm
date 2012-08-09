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

#include "point.h"

#include <GL/gl.h>

namespace Render
{

Point::Point(double x, double y, double z) throw()
	: m_x(x), m_y(y), m_z(z)
{
}

void Point::createVertice(void)const throw()
{
	///\todo make this inline
	glVertex3d(m_x, m_y, m_z);
}

Point &Point::operator+=(Point const &p) throw()
{
	m_x += p.m_x;
	m_y += p.m_y;
	m_z += p.m_z;
	return *this;
}

bool Point::operator==(Point const &p)const throw()
{
	return m_x == p.m_x && m_y == p.m_y && m_z == p.m_z;
}

Point operator+(Point const &p1, Point const &p2) throw()
{
	Point p(p1);
	p += p2;
	return p;
}

}
