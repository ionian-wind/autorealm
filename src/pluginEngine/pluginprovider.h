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

#ifndef PLUGINPROVIDER_H
#define PLUGINPROVIDER_H

#include <Pluma/Pluma.hpp>
#include <Pluma/Connector.hpp>

#include "plugin.h"

class PluginProvider: public pluma::Provider
{
private:
	friend class pluma::Pluma;
	static const unsigned int PLUMA_INTERFACE_VERSION;
	static const unsigned int PLUMA_INTERFACE_LOWEST_VERSION;
	static const std::string PLUMA_PROVIDER_TYPE;
	std::string plumaGetType() const{ return PLUMA_PROVIDER_TYPE; }
public:
	unsigned int getVersion() const{ return PLUMA_INTERFACE_VERSION; }
	virtual Plugin* create(RenderWindow*w) const = 0;
};

#endif // PLUGINPROVIDER_H
