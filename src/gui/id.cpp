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

#include "id.h"

#include <stdexcept>

#include <wx/utils.h>

uint16_t ID::s_nextID = wxNewId();

ID::ID(void)
: m_id(s_nextID)
{
	if(0xFFFF == s_nextID)
		throw std::runtime_error("Can not manage more than 65536 (0xFFFF)ID.\nPlease send a bug report.");

	++s_nextID;
}

ID::ID(uint16_t id) throw()
	: m_id(id)
{
}

inline const uint16_t ID::operator()(void)const throw()
{
	return m_id;
}

ID::operator uint16_t(void)const throw()
{
	return operator()();
}
