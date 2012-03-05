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

#include "object.h"
#include "Point.h"
#include "Color.h"

class Line //! Simple lines act as drawable vector, so they need only one coordinates.
: public Object
, public Point<> //! last point of the line.
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

    /** \brief say if a given point is on the line
     * \param point Point<> const&
     * \return virtual bool
     *
     */
    virtual bool find(Point<> const &point);

    /** \brief apply a rotation on an object
     * \param angle short angle in degree
     */
    void rotate(short degree);
    /** \brief apply a rotation on an object
     * \param radian float angle in radian
     */
    void rotate(float radian);
    /** \brief translate an object
     * \param distance const Point& distance to add to the current position of the object
     */
    void move(const Point<> & distance);
    /** \brief
     * \param widthPercent unsigned char
     * \param heightPercent unsigned char
     */
    virtual void resize(unsigned char widthPercent, unsigned char heightPercent);

    virtual void draw(void);
private:
    Color m_color;

};
#endif
