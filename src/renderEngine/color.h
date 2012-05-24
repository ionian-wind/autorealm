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

#ifndef COLOR_H
#define COLOR_H

class Color
{
	public:
        /** \brief default constructor */
		Color()=default;
        /** \brief constructor with initialization
         *
         *	\param red double
         *	\param green double
         *	\param blue double
         *	\param alpha double
		 *	\throw nothing
         */
		Color(double red, double green, double blue, double alpha) nothrow;

        /** \brief apply the color resulting of the combination
         *	this method simply call glColor4d. Its only use is encapsulation of openGL
         *	\throw nothing
         */
		void apply(void)const nothrow;
		double m_red, m_green, m_blue, m_alpha;
	protected:
	private:
};

#endif // COLOR_H
