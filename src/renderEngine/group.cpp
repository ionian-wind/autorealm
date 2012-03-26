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

#include "group.h"
#include "visitor.h"

#include <algorithm>

Group::Group(void)
:m_children()
{
}

void Group::accept(Visitor &v)
{
	//!\todo find a solution to use std::for_each
	for(CHILDLIST::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->accept(v);
	v.visit(*this);
}

void Group::draw(void)const
{
	for(CHILDLIST::const_iterator it = m_children.begin();it!=m_children.end();++it)
		(*it)->draw();
}

void Group::push_back(std::unique_ptr<Object>& target)
{
	m_children.push_back(std::move(target));
}