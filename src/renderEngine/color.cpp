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
Color::Color() = default;

Color::Color(double red, double green, double blue, double alpha) throw()
	: m_red(red*255), m_green(green*255), m_blue(blue*255), m_alpha(alpha*255)
{
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) throw()
	: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
{
}

Color::Color(std::string const& str)
{
	uint32_t color;
	if(1!=sscanf(str.c_str(),"%8x",&color))
		throw std::runtime_error("Unable to parse color string \""+str+"\"");
	m_red	=(color & (0xFF << (3*8)))>>(3*8);
	m_green	=(color & (0xFF << (2*8)))>>(2*8);
	m_blue	=(color & (0xFF << (1*8)))>>(1*8);
	m_alpha	=(color & (0xFF << (0*8)))>>(0*8);
}

inline void Color::draw(void)const throw()
{
	glColor4ub(m_red, m_green, m_blue, m_alpha);
}

Drawable* Color::clone(void) const
{
	return new Color(*this);
}

Color::operator std::string(void)const
{
	char strColors[9];
	uint32_t color=(m_red<<(3*8))+(m_green<<(2*8))+(m_blue<<(1*8))+(m_alpha<<(0*8));
	sprintf(strColors,"%08x",color);
	return strColors;
}

void Color::set(double r, double g, double b, double a)
{
	m_red=255*r;
	m_green=255*g;
	m_blue=255*b;
	m_alpha=255*a;
}

void Color::set(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	m_red=r;
	m_green=g;
	m_blue=b;
	m_alpha=a;
}
}
