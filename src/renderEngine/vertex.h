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

#include <memory>
#include <boost/serialization/split_member.hpp>
#include "point.h"

class Renderer;

namespace Render
{

class Vertex
{
	friend class ::boost::serialization::access;
    BOOST_SERIALIZATION_SPLIT_MEMBER();
	template<class Archive>
	void save(Archive &ar, const unsigned int version)const;
	template<class Archive>
	void load(Archive &ar, const unsigned int version);
public:
	Vertex(void);
	Vertex(Vertex const& other);
	Vertex(Point const& p, Renderer const& r);
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
	void draw(void)const;
	void setRenderer(Renderer const& next);

	~Vertex(void)throw();
	void place(void)const throw();

protected:
	Point m_point;
	std::unique_ptr<Renderer> m_renderer;
private:
};

}

#endif // VERTEX_H
