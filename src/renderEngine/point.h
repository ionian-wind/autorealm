/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU Lesser General Public License as published by        *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU Lesser General Public License for more details.                                *
 *                                                                                *
 *    You should have received a copy of the GNU Lesser General Public License           *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		double m_x,m_y,m_z;
        /** \brief default Ctor */
		Point() throw() =default;
        /** \brief Constructor with initialization of coordinates
         *	\param x double
         *	\param y double
         *	\param z double
         *	\throw nothing
         */
		Point(double x, double y, double z) throw();
        /** \brief simply encapsulate glVertex to avoid direct calls to openGL
         *	\throw nothing
         */
		void createVertice(void)const throw();
        /** \brief increment a vertex with the value of another
         *	\param const&p1 Point vertex to add
         *	\return Point& reference to this
         *	\throw nothing
         */
		Point& operator+=(Point const&p1) throw();
        /** \brief test if two vertices are identical
         * \param const&p Point vertex to compare to this
         * \return bool true if vertices are the same
         */
		bool operator==(Point const&p)const throw();
	protected:
	private:
};

/** \brief increment a vertex with the value of another
 *	\param const&p1 Point vertex to add
 *	\return Point copy of the resulting vertex
 *	\throw nothing
 */
Point operator+(Point const&p1, Point const&p2) throw();

#endif // POINT_H
