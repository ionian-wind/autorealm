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

#ifndef VERTEX_H
#define VERTEX_H

#include "point.h"
#include "color.h"
#include "drawable.h"

namespace Render
{

class Vertex : public Drawable
{
	friend class boost::serialization::access;
public:
	/** \brief default constructor */
	Vertex(void) throw() = default;
	/** \brief constructor with initialization
	 *	\param end Point const&
	 *	\param color Color const&
	 *	\param drawer Drawer*
	 *	\throw nothing
	 */
	Vertex(Point const &end) throw();
	/** \brief copy ctor
	 *	\param const&other Vertex
	 *	\throw nothing
	 */
	Vertex(Vertex const &other) throw();

	/** \brief copy another vertex
	 *	\param const&v Vertex
	 *	\return Vertex&
	 *	\throw nothing
	 */
//	Vertex &operator=(Vertex const &v) throw();
	/** \brief test if two vertex are the same
	 *	\note currently, only the position is used to compare two vertices
	 *	\param const&other Vertex
	 *	\return bool true if vertices are the same
	 *	\throw nothing
	 */
	bool operator==(Vertex const &other)const throw();

	/** \brief return (a copy of the) coordinates of the ending point
	 *	\return Point
	 *	\throw nothing
	 */
	Point getEnd(void)const throw();
	/** \brief use (a copy of) p as new ending coordinates
	 *	\param p Point const&
	 *	\throw nothing
	 */
	void setEnd(Point const &p) throw();
private:
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version);

protected:
	Point m_point;
private:
};

}

#endif // VERTEX_H
