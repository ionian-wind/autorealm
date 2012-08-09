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

void Group::accept(Mutator &v)
{
	///\todo find a solution to use std::for_each
	v.visit(*this);

	for(auto & i : m_children)
		i->accept(v);
}

void Group::draw(void)const throw()
{
	for(auto it = m_children.rbegin(); it != m_children.rend(); ++it)
		//		auto &i:m_children)
		(*it)->draw();
}

void Group::push_back(std::unique_ptr<Object> target)
{
	m_children.push_back(std::move(target));
}

void Group::apply(void)const throw()
{
	draw();
}

std::unique_ptr<Drawable> Group::clone(void)const
{
	std::unique_ptr<Drawable> group(new Group(*this));
	return group;
}

Group::Group(Group const &g)
	: m_children()
{
	for(auto & i : g.m_children)
		m_children.push_back(std::move(std::unique_ptr<Group>(dynamic_cast<Group *>(i->clone().get()))));
}

}
