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

class Drawer;

namespace Render
{

class Vertex
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
	Vertex(Point const &end, Drawable const &drawable, Drawer &drawer) throw();
	/** \brief copy ctor
	 *	\param const&other Vertex
	 *	\throw nothing
	 */
	Vertex(Vertex const &other) throw();
	/** \brief destructor */
	~Vertex(void) throw();
	/** \brief initialize the vertex with new values
	 *	\param end Point const& coordinates of the last point of the vertex
	 *	\param color Color const& color of the last point of the vertex
	 *	\param drawer Drawer* algorithm used to render the line which will end to the vertex
	 *	\throw nothing
	 */
	void set(Point const &end, Drawable const &drawable, Drawer const&drawer) throw();
	/** \brief copy another vertex
	 *	\param const&v Vertex
	 *	\return Vertex&
	 *	\throw nothing
	 */
	Vertex &operator=(Vertex const &v) throw();
	/** \brief test if two vertex are the same
	 *	\note currently, only the position is used to compare two vertices
	 *	\param const&other Vertex
	 *	\return bool true if vertices are the same
	 *	\throw nothing
	 */
	bool operator==(Vertex const &other)const throw();
	/** \brief render a vertex
	 *	If drawable is set, the drawable is used instead of the drawable of the vertex.
	 *	This is usefull to create shapes filled with a given drawable, by example.
	 *	\param drawable=nullptr REDrawable const* drawable to use to render. If it is a nullptr, then the vertex's one is used
	 *	\throw nothing
	 *	\todo check if it is realistic to say Drawer::draw can not throw
	 */
	void render(Drawable const &drawable)const throw();
	void render(void)const throw();
	/** \brief Change the algorithm used to render
	 *	\param newRender Drawer*
	 *	\throw nothing
	 */
	void changeRender(Drawer const &newRender) throw();

	/** \brief get a copy of the drawable
	 *	\return Drawable*
	 *	\throw nothing
	 */
	Drawable& getDrawable(void)const throw();
	/** \brief change the drawable to a copy of d
	 *	\param d Drawable const*
	 *	\throw nothing
	 */
	void setDrawable(Drawable const &d) throw();

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
	void serialize(Archive &ar, const unsigned int version)
	{
		ar &m_drawable;
		ar &m_point;
		ar &m_drawer;
	}

protected:
	Drawable *m_drawable;
	Point m_point;
	Drawer* m_drawer;
private:
};

}

#endif // VERTEX_H
