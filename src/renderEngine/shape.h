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

#include <vector>
#include <memory>

#include "object.h"
#include "color.h"

//class Vertex;
#include "vertex.h"
class Point;

class Shape : public Object
{
	public:
		/** Destructor */
		~Shape(void) throw();
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
        /** \brief add a new point to the shape
         *	\note A copy of the vertex is made before adding it to the shape
         *	\param const&target Vertex vertex to add.
         */
		void push_back(Vertex const&target);

        /** \brief change the color used to fill the shape
		 *	\note a copy of the color is used
         *	\param const&c Color color to use
         */
		void setFiller(Color const&c) throw();
        /** \brief retrieve color used to fill the shape
         *	\return Color copy of the color used
         */
		Color getFiller(void)const throw();

        /** \brief retrieve an iterator on the first vertex
         *	\todo check if this method is really mandatory, because it breaks the encapsulation
         *	\return std::vector<Vertex>::iterator
         */
		std::vector<Vertex>::iterator getFirstChild(void) throw();

        /** \brief retrieve on iterator after the last vertex
         *	\todo check if this method is really mandatory, because it breaks the encapsulation
         *	\return std::vector<Vertex>::iterator
         */
		std::vector<Vertex>::iterator getLastChild(void) throw();
	protected:
	private:
	protected:
		Color m_filler;
	private:
		std::vector<Vertex> m_children;
};

#endif // SHAPE_H
