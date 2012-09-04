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

#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <string>
#include <vector>

class TextFile;

#include "singleton.h"

class AppConfig: public Singleton<AppConfig>
{
	std::vector<std::string> m_datas;
public:
	enum INFO {GRP_RES = 0, PLUGINS, MENU, LASTINDEX};
	/** \brief retrieve data from a configuration file */
	AppConfig();
	/**	\brief retrieve the needed path from stored datas
	 *	Stored datas are read from file config. It's location depends on your OS
	 *	\param INFO name of the data to retrieve
	 */
	static std::string buildPath(INFO info);
};

#endif // APPCONFIG_H
