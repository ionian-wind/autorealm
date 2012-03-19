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

#ifndef _OBJECT_H
#define _OBJECT_H

#include <vector>

#include "Point.h"
class Group;

class Object //! abstract class which implement common transformations and impose the name of drawing method
{
public:
protected:
	typedef std::vector<Object*> Children;
private:
	friend class Group;

public:
protected:
    Group *m_owner;
private:

public:
    /** \brief Contructor. The owner is mandatory, except for the render window (which is itself considered as an object)
     * \param owner Group* group which own the future object
     */
    Object(Group *owner);

    /** \brief apply a rotation on an object
     * \param angle short angle in degree
     */
    virtual void rotate(short degree)=0;
    /** \brief apply a rotation on an object
     * \param radian float angle in radian
     */
    virtual void rotate(float radian)=0;
    /** \brief translate an object
     * \param distance const Point& distance to add to the current position of the object
     */
    virtual void move(const Point<> & distance)=0;
    /** \brief
     * \param widthPercent unsigned char
     * \param heightPercent unsigned char
     */
    virtual void resize(unsigned char widthPercent, unsigned char heightPercent)=0;
    /** \brief draw the object on the plan
     */
    virtual void draw()=0;
protected:
    /** \brief Default Ctor.
     * This Ctor is protected because the plan itself is considered as a Group,
     * so groups will very rarely need default Ctor.
     * The probably only exception on that is the renderWindow.
     */
    Object(void);
};

#endif
