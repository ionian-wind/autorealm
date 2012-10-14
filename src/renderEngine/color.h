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

#ifndef COLOR_H
#define COLOR_H

#include <boost/serialization/access.hpp>

#include "drawable.h"

namespace Render
{

class Color : public Drawable
{
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version);
	uint8_t m_red=0, m_green=0, m_blue=0, m_alpha=255;

public:
	/** \brief default constructor */
	Color();
	/** \brief constructor with initialization
	 *
	 *	\param red double
	 *	\param green double
	 *	\param blue double
	 *	\param alpha double
	 *	\throw nothing
	 */
	Color(double red, double green, double blue, double alpha) throw();
	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) throw();
	Color(std::string const& str);

	/** \brief apply the color resulting of the combination
	 *	this method simply call glColor4d. Its only use is encapsulation of openGL
	 *	\throw nothing
	 */
	void draw(void)const throw() override;
	Drawable* clone(void) const override;
	operator std::string(void)const;
	void set(double r, double g, double b, double a);
	void set(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};

}

#endif // COLOR_H
