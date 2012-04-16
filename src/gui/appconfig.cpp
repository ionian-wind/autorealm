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

#include "appconfig.h"

AppConfig::AppConfig()
{
	//!\todo retrieve those informations from a configuration file
	std::string root="/home/berenger/autorealm/";

	m_configfiles=root+"config/";
	m_graphicalResources=root;
	m_pluginsConfig="plugins/";
}

std::string AppConfig::buildPath(INFO info)
{
	switch(info)
	{
	case GRP_RES:
		return GetInstance().m_graphicalResources;
	case CONFIG:
		return GetInstance().m_configfiles;
	case PLUGINS:
		return GetInstance().m_pluginsConfig;
	default:
		return "";
	}
}
