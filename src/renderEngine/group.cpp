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

#include "group.h"

#include <algorithm>

#include <pluginEngine/mutator.h>

namespace Render
{

Group::~Group(void)throw()
{
	for(Object* i:m_children)
		delete i;
}

void Group::accept(Mutator &v)
{
	///\todo find a solution to use std::for_each
	v.visit(*this);

	for(Object* i : m_children)
		i->accept(v);
}

void Group::draw(void)const throw()
{
	for(ObjectList::const_reverse_iterator rit=m_children.rbegin();m_children.rend()!=rit;++rit)
		(*rit)->draw();
}

void Group::push_back(Object *target)
{
	m_children.push_back(target);
}

Drawable* Group::clone(void)const
{
	return new Group(*this);
}

Group::Group(Group const &g)
	: m_children()
{
	for(Object *i : g.m_children)
		m_children.push_back(dynamic_cast<Object*>(i->clone()));
}

template<class Archive>
void Group::serialize(Archive &ar, const unsigned int version)
{
	ar &m_children;
}

}
