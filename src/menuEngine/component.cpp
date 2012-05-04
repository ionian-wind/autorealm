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

#include "component.h"

#include <assert.h>

#include <utils/textfile.h>

void Component::loadConfiguration(std::unique_ptr<TextFile> &file)
{
	m_name=file->readLine();
}

std::string Component::getPluginName(void)const
{
	return getName();
}

void Component::disable(bool disable)
{
	m_enable=!disable;
}

bool Component::isEnabled(void)const
{
	return m_enable;
}

std::string Component::getName(void)const
{
	return m_name;
}