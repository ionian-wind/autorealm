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

Vertex::Vertex(Point const &end, Color const &color,std::unique_ptr<Drawer> drawer) throw()
:m_color(color),m_point(end),m_drawer(std::move(drawer))
{
	//!\todo make it inline
}

Vertex::Vertex(Vertex const&other) throw()
:m_color(other.m_color),m_point(other.m_point),m_drawer(other.m_drawer->clone())
{
	//!\todo make it inline
}

Vertex::~Vertex(void) throw()
{
	//!\todo make it inline
	m_drawer.reset();
}

void Vertex::set(Point const &end, Color const &color,std::unique_ptr<Drawer> drawer) throw()
{
	//!\todo make it inline
	m_color=color;
	m_point=end;
	m_drawer=std::move(drawer);
}

Vertex& Vertex::operator=(Vertex const&v) throw()
{
	//!\todo make it inline
	set(v.m_point, v.m_color, v.m_drawer->clone());
	return *this;
}

bool Vertex::operator==(Vertex const&other)const throw()
{
	//!\todo make it inline
	return m_point==other.m_point;
}

void Vertex::render(Color const *color) const throw()
{
	if(!color)
		m_drawer->draw(*this);
	else
	{
		Vertex v=clone();
		v.setColor(*color);
		m_drawer->draw(v);
	}
}

void Vertex::changeRender(std::unique_ptr<Drawer> newRender) throw()
{
	//!\todo make it inline
	m_drawer=std::move(newRender);
}

Vertex Vertex::clone(void)const
{
	//!\todo make it inline
	return Vertex( m_point, m_color, m_drawer->clone());
}

Color Vertex::getColor(void)const throw()
{
	//!\todo make it inline
	return m_color;
}

Point Vertex::getEnd(void)const throw()
{
	//!\todo make it inline
	return m_point;
}

void Vertex::setColor(Color const &c) throw()
{
	//!\todo make it inline
	m_color=c;
}

void Vertex::setEnd(Point const &p) throw()
{
	//!\todo make it inline
	m_point=p;
}
