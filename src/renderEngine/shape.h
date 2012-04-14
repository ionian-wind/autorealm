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

#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <memory>

#include "object.h"
#include "color.h"

class Point;
class Vertex;

class Shape : public Object
{
	public:
		void accept(Visitor &v);
		void draw(void)const;

		bool isClosed(void)const throw();
		void push_back(Vertex const&target);

		void setFiller(Color const&c);
		Color getFiller(void)const;

		std::vector<Vertex>::iterator getFirstChild(void);
		std::vector<Vertex>::iterator getLastChild(void);
	protected:
	private:
	protected:
		Color m_filler;
	private:
		std::vector<Vertex> m_children;
};

#endif // SHAPE_H
