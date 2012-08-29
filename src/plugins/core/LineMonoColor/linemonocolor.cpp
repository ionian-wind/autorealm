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

#include <renderEngine/vertex.h>

LineMonoColor::LineMonoColor(LineMonoColor const &other)
:GraphicPrimitive(other),m_color(other.m_color)
{
}

LineMonoColor::LineMonoColor(Render::Color const& color)
:m_color(color)
{
}

void LineMonoColor::draw(void)const throw()
{
	m_point.createVertice();
	m_color.draw();
	m_point.createVertice();
}

Render::Drawable* LineMonoColor::clone(void)const
{
	return static_cast<Render::Drawable*>(new LineMonoColor(*this));
}
