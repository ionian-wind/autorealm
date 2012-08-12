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

#include "vertex.h"

#include <assert.h>

#include "shape.h"
#include <pluginEngine/drawer.h>

namespace Render
{

Vertex::Vertex(Point const &end, Drawable const *drawable, Drawer *drawer) throw()
	: m_drawable(), m_point(end), m_drawer(drawer)
{
	m_drawable.reset(drawable->clone());
	///\todo make it inline
}

Vertex::Vertex(Vertex const &other) throw()
	: m_drawable(), m_point(other.m_point), m_drawer(other.m_drawer->clone())
{
	m_drawable.reset(other.m_drawable->clone());
	///\todo make it inline
}

Vertex::~Vertex(void) throw()
{
	///\todo make it inline
	assert(m_drawer);//m_drawer should NEVER be null
	delete m_drawer;
}

void Vertex::set(Point const &end, Drawable const *drawable, Drawer* drawer) throw()
{
	///\todo make it inline
	m_drawable.reset(drawable->clone());
	m_point = end;
	m_drawer = drawer;
}

Vertex &Vertex::operator=(Vertex const &v) throw()
{
	///\todo make it inline
	set(v.m_point, v.m_drawable->clone(), v.m_drawer->clone());
	return *this;
}

bool Vertex::operator==(Vertex const &other)const throw()
{
	///\todo make it inline
	return m_point == other.m_point;
}

void Vertex::render(Drawable const *drawable) const throw()
{
	if(!drawable)
		m_drawer->draw(*this);
	else
	{
		Vertex v = clone();
		v.setDrawable(drawable);
		m_drawer->draw(v);
	}
}

void Vertex::changeRender(Drawer* newRender) throw()
{
	///\todo make it inline
	m_drawer = newRender;
}

Vertex Vertex::clone(void)const
{
	///\todo make it inline
	return Vertex(m_point, m_drawable->clone(), m_drawer->clone());
}

Drawable& Vertex::getDrawable(void)const throw()
{
	///\todo make it inline
	return *m_drawable;
}

void Vertex::setDrawable(Drawable const *d) throw()
{
	///\todo make it inline
	m_drawable.reset(d->clone());
}

Point Vertex::getEnd(void)const throw()
{
	///\todo make it inline
	return m_point;
}

void Vertex::setEnd(Point const &p) throw()
{
	///\todo make it inline
	m_point = p;
}

}
