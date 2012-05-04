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

#include "menuitem.h"

#include <assert.h>

#include <utils/textfile.h>

void IComponent::loadConfiguration(std::unique_ptr<TextFile> &file)
{
	m_name=file->readLine();
//	m_name=file->getFileName();
}
//
//void IComponent::init(boost::filesystem::path const &file)
//{
//	//!\pre file must be a regular file
//	assert(boost::filesystem::is_regular_file(file));
//	m_name=file.filename().string();
//	//!\todo read name of the entry from the file
//	//!\todo read kind of entry from the file
//}

std::string IComponent::getPluginName(void)const
{
	return getName();
}

void IComponent::disable(bool disable)
{
	m_enable=!disable;
}

bool IComponent::isEnabled(void)const
{
	return m_enable;
}

std::string IComponent::getName(void)const
{
	return m_name;
}
