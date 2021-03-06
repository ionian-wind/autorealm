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

#ifndef SHAPE_H
#define SHAPE_H

#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

#include "object.h"
#include "vertex.h"

class Renderer;

namespace Render
{

class Shape : public Object
{
	typedef std::vector<Vertex> DrawableList;
	DrawableList m_children;
	std::unique_ptr<Renderer> m_filler;
	bool m_close=false;

	friend class ::boost::serialization::access;
//	BOOST_SERIALIZATION_SPLIT_MEMBER();
//
//	template<class Archive>
//	void save(Archive &ar, const unsigned int version)const;
//
//	template<class Archive>
//	void load(Archive &ar, const unsigned int version);
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version);

public:
	Shape(void);
	Shape(Shape const& other);
	/** \brief Apply an algorithm on itself
	 * \param v Mutator& algorithm to apply
	 */
	void accept(Mutator &v);
	/** \brief draw the shape
	 *	\throw nothing
	 *	\todo check if it is possible and realistic to avoid Vertex throwing
	 */
	void draw(void)const throw();

	/** \brief test if the Shape is closed or opened figure
	 *	\return bool true if the shape is closed
	 *	\throw nothing
	 */
	bool isClosed(void)const throw();

	void addVertex(Point const& p, Renderer const& r);
	void pop(void)throw();

	/** \brief change the drawable used to fill the shape
	 *	\note a copy of the drawable is used
	 *	\param d REDrawable const* drawable to use
	 */
	void setFiller(Renderer const&d) throw();

	/** \brief close the shape */
	void close(void) throw();

	virtual Shape* clone(void)const override;
	bool empty(void)const throw();
	void clear(void)throw();

protected:
private:
	inline void checkSize(void)const;
};

}

#endif // SHAPE_H
