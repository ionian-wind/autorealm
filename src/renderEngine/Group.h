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

#ifndef _GROUP_H
#define _GROUP_H

#include <vector>
#include <tr1/memory>

#include "object.h"

class Group //! Object which contain other objects and allow to manipulate the whole set in one action
: public Object
{
private:
protected:
	typedef std::vector<Object*> Children;

public:
    /** \brief Contructor.
     * Avoid creation of empty groups or groups without container.
     * Take the ownership of the targets
     * \param targets std::vector<Object&>& objects the group will take as it's parts
     * \param owner Group* container of the group
     */
    Group(Children & targets, Group *owner);

    /** \brief change the ownership of all children to the object's owner
     * This method have as primary goal to remove a group without deleting what
	 * it contains.
     */
    void dismiss(void);
    /** \brief draw children of the group.
	 * \warning risk of sigsev due to the owner->erase(this) trick
     */
    void draw(void);
    /** \brief delete a Group
     * \warning If the deleted group is not empty, it's content is deleted, too.
     * \param target Group &
     */
    void erase(Object *target);
    /** \brief add a single object to the group.
     * The group take the ownership of the object.
     * \param target Object &
     */
	void push(Object *target);

    /** \brief apply a rotation on an object
     * \param angle short angle in degree
     */
    virtual void rotate(short degree);
    /** \brief apply a rotation on an object
     * \param radian float angle in radian
     */
    virtual void rotate(float radian);
    /** \brief translate an object
     * \param distance const Point& distance to add to the current position of the object
     */
    virtual void move(const Point<> & distance);
    /** \brief
     * \param widthPercent unsigned char
     * \param heightPercent unsigned char
     */
    virtual void resize(unsigned char widthPercent, unsigned char heightPercent);
protected:
    /** \brief Default Ctor.
     * This Ctor is protected because the plan itself is considered as a Group,
     * so groups will very rarely need default Ctor.
     * The probably only exception on that is the renderWindow.
     */
    Group(void);
public:
protected:
    std::vector<Object*> m_children;
private:
};
#endif
