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

Vertex::Vertex(Point const &end) throw()
	: m_point(end)
{
	///\todo make it inline
}

//Vertex &Vertex::operator=(Vertex const &v) throw()
//{
//	///\todo make it inline
//	Vertex vv(v);
//	std::swap(*this,vv);
//	return *this;
//}
//
bool Vertex::operator==(Vertex const &other)const throw()
{
	///\todo make it inline
	return m_point == other.m_point;
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

template<class Archive>
void Vertex::serialize(Archive &ar, const unsigned int version)
{
	ar &m_point;
}

}
