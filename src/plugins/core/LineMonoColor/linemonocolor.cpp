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

#include "linemonocolor.h"

#include <gui/renderwindow.h>
#include <renderEngine/vertex.h>

LineMonoColor::LineMonoColor(void)
:Drawer(),m_color()
{
}

LineMonoColor::LineMonoColor(LineMonoColor const &other)
:Drawer(other),m_color(other.m_color)
{
}

void LineMonoColor::draw(void)const throw()
{
	m_color.draw();
}

Drawer* LineMonoColor::clone(void)const
{
//	LineMonoColor* tmp(new LineMonoColor(*this));
//	tmp->m_color=m_target->getFillerColor();
//	return static_cast<Render::Drawable*>(tmp);
	return new LineMonoColor(*this);
}
