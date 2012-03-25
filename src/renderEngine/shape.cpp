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

#include "shape.h"

#include <algorithm>

#include "line.h"
#include "visitor.h"

Shape::Shape(void)
:Object(),m_filler(),m_start(),m_children()
{
}

void Shape::accept(Visitor &v)
{
	v.visit(*this);
	for(CHILDLIST::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->accept(v);
	//!\todo find a solution to use std::for_each
}

Point Shape::getStart(void)
{
	return m_start;
}

Color Shape::getFiller(void)
{
	return m_filler;
}

bool Shape::isClosed(void)
{
	return m_children.front()==m_children.back();
}

void Shape::push_back(std::unique_ptr<Line>& target)
{
	m_children.push_back(std::move(target));
}
