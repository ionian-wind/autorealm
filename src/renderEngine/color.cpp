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

#include "color.h"

#include <GL/gl.h>

namespace Render
{

Color::Color(double red, double green, double blue, double alpha) throw()
:m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
{
}

void Color::apply(void)const throw()
{
	//!\todo make this inline
	glColor4d(m_red,m_green,m_blue,m_alpha);
}

std::unique_ptr<Drawable> Color::clone(void)const
{
	std::unique_ptr<Drawable> col(new Color(*this));
	return col;
}

}
