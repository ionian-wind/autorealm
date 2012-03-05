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

#ifndef _LINE_H
#define _LINE_H


#include "Point.h"
#include "Color.h"

class Line //! Simple lines act as drawable vector, so they need only one coordinates.
: public Point<> //! last point of the line.
{
public:
	Line(void):Point<>(),m_color(){}
	Line(Point<> const &pt):Point<>(pt),m_color(){}

    /** \brief draw the line
     * \param ignoreColor=false bool /!\ currently unused /!\ if true, do not draw the line
     */
    virtual void lineDraw(bool ignoreColor=false)const;
    /** \brief split a line into two identical ones
     * \param cutPoint Point const&
     */
	virtual void split(Point<> const &cutPoint);
    virtual bool find(Point<> const &point);
private:
    Color m_color;

};
#endif
