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

#ifndef TDRAWERPROVIDER_H
#define TDRAWERPROVIDER_H

#include <vector>
#include <string>

#include "pluginprovider.h"
#include "drawer.h"

template <typename Renderer>
class TDrawerProvider: public PluginProvider
{
public:
	typedef std::vector<std::string> TagList;
	TagList m_tagList;

	Plugin * create(RenderWindow*w) const
	{
		return new Drawer(w, std::unique_ptr<Renderer>(new Renderer()), m_tagList);
	}
};


#endif // TDRAWERPROVIDER_H
