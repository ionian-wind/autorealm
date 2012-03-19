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

#include <algorithm>

#include "Group.h"
#include "Shape.h"

Group::Group(Children &targets, Group *owner)
:Object(owner)
{
	m_children.assign(targets.begin(),targets.end());
	for(Children::iterator it=targets.begin();it!=targets.end();++it)
		(*it)->m_owner->erase(*it);
}

void Group::dismiss(void)
{
    for(Children::iterator it=m_children.begin(); it!=m_children.end(); ++it)
        m_owner->push(*it);
    m_owner->erase(this);
}

void Group::draw(void)
{
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(draw));
	for(Children::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->draw();
}

void Group::push(Object *target)
{
	target->m_owner=this;
	m_children.push_back(target);
	target=0;
}

void Group::erase(Object *target)
{
	m_children.erase(std::find(m_children.begin(),m_children.end(),target));
}

Group::Group(void)
{
}

void Group::rotate(short degree)
{
}

void Group::rotate(float radian)
{
}

void Group::move(const Point<> & distance)
{
}

void Group::resize(unsigned char widthPercent, unsigned char heightPercent)
{
}

#warning untested implementation
