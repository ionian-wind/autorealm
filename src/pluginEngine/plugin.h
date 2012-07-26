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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <string>
#include <Pluma/Pluma.hpp>

class RenderWindow;

class Plugin
{
	public:
		virtual void installEventManager(RenderWindow & target) throw() =0;
		virtual void removeEventManager(void) throw() =0;
	protected:
		static const std::string m_configFileName;
		RenderWindow *m_target;
	private:
};

PLUMA_PROVIDER_HEADER(Plugin);

#endif // PLUGIN_H
