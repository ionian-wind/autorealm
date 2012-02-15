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


#include "Group.h"
#include "Shape.h"

Group::Group(const std::vector<Object> & targets, Group *owner)
:Object(owner)
{
}

void Group::dismiss(void)
{
    //WARNING (berenger#1#) risk of sigsev due to the owner->remove(this) trick
    for(std::vector<Object>::iterator it=m_children.begin(); it!=m_children.end(); it++)
        m_owner->add(*it);
    m_owner->remove(this);
}

void Group::draw(void)
{
    for(std::vector<Object>::iterator it=m_children.begin(); it!=m_children.end(); it++)
        it->draw();
}

void Group::add(Object const &target)
{
}

void Group::remove(Group *target)
{

}
