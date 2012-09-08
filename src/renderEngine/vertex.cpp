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

#include <pluginEngine/drawer.h>

namespace Render
{

Vertex::Vertex(void)=default;

Vertex::Vertex(Vertex const& other)
:m_point(other.m_point),m_renderer(other.m_renderer->clone())
{
}

Vertex::Vertex(Point const& p, Drawer const& d)
:m_point(p)
,m_renderer(d.clone())
{
}

inline bool Vertex::operator==(Vertex const &other)const throw()
{
	return m_point == other.m_point;
}

Point Vertex::getEnd(void)const throw() ///\todo make inline
{
	return m_point;
}

void Vertex::setEnd(Point const &p) throw() ///\todo make inline
{
	m_point = p;
}

void Vertex::draw(void)const
{
	m_point.createVertice();
	m_renderer->draw();
	m_point.createVertice();
}

void Vertex::setDrawer(Drawer const& next)
{
	m_renderer.reset(next.clone());
}

template<class Archive>
void Vertex::serialize(Archive &ar, const unsigned int version)
{
	ar &m_point;
}

Vertex::~Vertex(void)throw()
{
	m_renderer.reset();
}

void Vertex::place(void)const throw()
{
	m_point.createVertice();
}

}
