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

#ifndef _POINT_H
#define _POINT_H

template <typename T=double>
/** \brief structure to manipulate positions
 * \note The template parameter can allow type optimizations, like changing double for float.
 * \note This structure is more a vector in mathematical point of vue than a true point.
 */
struct Point
{
public:
    T m_x, m_y, m_z;

	Point(void)
	:m_x(),m_y(),m_z(){}

	Point(T x,T y,T z)
	:m_x(x),m_y(y),m_z(z){}

	Point& operator+=(Point const& target)
	{
		m_x+=target.m_x;
		m_y+=target.m_y;
		m_z+=target.m_z;
		return *this;
	}

	bool operator==(Point const& target)
	{
		if(m_x==target.m_x&&m_y==target.m_y&&m_z==target.m_z)
			return true;
		return false;
	}

};

#endif
