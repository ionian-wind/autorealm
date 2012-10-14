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

#ifndef ID_H
#define ID_H

#include <stdint.h>

class ID
{
	static uint16_t s_nextID;
	const uint16_t m_id;
public:
	/** \brief take an unused ID number
	 *	\pre s_nextID != 0xFFFF
	 *	\post s_nextID is incremented
	 */
	ID(void);
	/** \brief copy an ID number
	 *	\invariant s_nextID
	 *	\param id unsigned long
	 */
	ID(uint16_t id) throw();
	/** \brief get the stored number
	 * \return const uint16_t
	 */
	const uint16_t operator()(void)const throw();
	/** \brief cast operator to int
	 *	\return copy of m_id
	 */
	operator uint16_t(void)const throw();
};

#endif // ID_H
