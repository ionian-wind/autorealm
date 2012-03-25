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

#include "object.h"

#include <vector>
#include <memory>

#include "point.h"
#include "color.h"

class Line;

class Shape : public Object
{
	typedef std::vector<std::unique_ptr<Line>> CHILDLIST;
	public:
		Shape(void);
		virtual void accept(Visitor &v);
		Point getStart(void);
		Color getFiller(void);
		bool isClosed(void);
		void push_back(std::unique_ptr<Line>& target);
	protected:
		Color m_filler;
		Point m_start;
	private:
		CHILDLIST m_children;
};

#endif // SHAPE_H
