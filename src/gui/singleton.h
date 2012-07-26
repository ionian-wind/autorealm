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

#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
/** \brief A singleton template. Classic and so undocumented. */
class Singleton
{
	static T *m_Instance;
public:
	static T &GetInstance(void)
	{
		if(!m_Instance)
			m_Instance=new T;
		return static_cast<T&>(*m_Instance);
	}
protected:
	Singleton()=default;
	virtual ~Singleton()=default;
};

template <class T>
T *Singleton<T>::m_Instance = 0;

#endif // SINGLETON_H

