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

#include <assert.h>
#include <utils/textfile.h>

template <class T>
void Component<T>::loadConfiguration(std::unique_ptr<TextFile> &file)
{
	m_name=file->readLine();
}

template <class T>
std::string Component<T>::getPluginName(void)const
{
	return getName();
}

template <class T>
void Component<T>::disable(bool disable)
{
	m_enable=!disable;
}

template <class T>
bool Component<T>::isEnabled(void)const
{
	return m_enable;
}

template <class T>
std::string Component<T>::getName(void)const
{
	return m_name;
}
