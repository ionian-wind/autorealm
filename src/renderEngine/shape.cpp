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

#include "shape.h"

#include <algorithm>
#include <stdexcept>

#include <GL/gl.h>

#include <pluginEngine/mutator.h>

namespace Render
{

void Shape::accept(Mutator &v)
{
	///\todo find a solution to use std::for_each
	v.visit(*this);
}

void Shape::draw(void)const throw()
{
	checkSize();

	//!\todo implement tesselation to manage concave polygons
	glBegin(GL_LINE_STRIP);

	for(auto &i : m_children)
		i.draw();
	if(m_close)
		m_children.front().draw();

	glEnd();

	if(isClosed())
	{
//		throw std::logic_error("not implemented yet");
		glBegin(GL_POLYGON);
		m_filler->draw();

		for(auto &i : m_children)
			i.getEnd().createVertice();
		if(m_close)
			m_children.front().getEnd().createVertice();

		glEnd();
	}
}

bool Shape::isClosed(void)const  throw()
{
	return m_close;
}

void Shape::push(Vertex const & target)
{
	m_children.push_back(target);
}

void Shape::pop(void)throw()
{
	if(m_children.empty())
		throw std::logic_error("Can not pop an element when container is empty");
	m_children.pop_back();

//	checkSize();
}

void Shape::setFiller(Drawable const &d) throw()
{
	m_filler=d;
}

clone_ptr<Drawable> Shape::getFiller(void)const throw()
{
	return m_filler;
}

Vertex& Shape::getFirstChild(void) throw()
{
	return *m_children.begin();
}

Vertex& Shape::getLastChild(void) throw()
{
	return *m_children.end()--;
}

void Shape::close(void) throw()
{
	m_close=true;
}

Drawable* Shape::clone(void)const
{
	return new Shape(*this);
}

template<class Archive>
void Shape::serialize(Archive &ar, const unsigned int version)
{
	ar &m_filler;
	ar &m_children;
}

inline void Shape::checkSize(void)const
{
	if(2>m_children.size())
		throw std::logic_error("Shape must always have at least two points");
}

}
