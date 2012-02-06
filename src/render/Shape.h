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

#ifndef _SHAPE_H
#define _SHAPE_H


#include "Object.h"
#include <vector>
#include "Color.h"

class Line;
class Point;

class Shape : public Object
{
  private:
	std::vector<Line> m_lines;
	Color m_filler;
	bool m_closed;

  public:
    Shape split();
    void merge(const Shape & target);
    void close(bool close);
    void createPoint(const Point & target);
    void addPoint(const Point & target);
    void removePoint(const Point & target);
    Shape(const Point & origin);
    virtual void draw();

};
#endif
