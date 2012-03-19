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

#include <vector>
#include <tr1/memory>

#include "object.h"
#include "Color.h"

class Line;

class Shape //! Shape are Groups composed by a point followed by lines
: public Object
{
	typedef std::vector<Line*> Children;
public:
protected:
    bool m_closed;

private:
	Children m_children;
    Color m_filler;
    Point<> m_position;

public:
    /** \brief send a part of the shape into another one, and return the resulting shape.
     * Original shape and created one share the same owner.
     * \param beginBreak Point const& first point of the future shape
     * \param endBreak Point const& last point of the future shape
     * \return Shape
     */
    Shape split(Point<> const &beginBreak,Point<> const &endBreak);
    /** \brief merge the shape with another one.
     * the target shape is removed.
     * \param target const Shape&
     */
    void merge(Shape *target);
    /** \brief make the shape a closed figure
     * \param close bool
     */
    void close(bool close);
    /** \brief split a line into two lines
     * \param target const Line& new line's starting position
     */
    void insert(Line const & target);
    /** \brief add a line at the end of the shape
     * \param target const Line& coordinate where the new line will ends.
     */
    void push_back(const Line & target);
    /** \brief remove a line from the shape
     * \note Removing a line will make the previous one ending at the position of the next one, exactly if lines were a chained list
     * \param target const Line&
     */
    void erase(const Line & target);
    /** \brief Create a shape with given lines.
     * \param begin LineChildren::iterator const&
     * \param end LineChildren::iterator const&
     */
    Shape(std::vector<Line*>::iterator const &begin,std::vector<Line*>::iterator const &end);
    /** \brief Create a single ligne shape
     *
     * \param position Point const&
     * \param end Line const&
     *
     */
    Shape(Point<> const &position,Line const &end);

    virtual void rotate(short degree);
    virtual void rotate(float radian);
    virtual void resize(uint8_t width, uint8_t height);

    /** \brief draw the shape */
    void draw();

    /** \brief translate an object
     * \param distance const Point& distance to add to the current position of the object
     */
    virtual void move(const Point<> & distance);
protected:
	void drawShape(bool ignoreColor=false);
};
#endif
