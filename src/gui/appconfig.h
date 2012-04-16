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

#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <string>

#include "singleton.h"

class AppConfig:public Singleton<AppConfig>
{
	public:
		enum INFO{GRP_RES, CONFIG, PLUGINS};
        /** \brief
         * \todo retrieve data from a configuration file
         */
		AppConfig();
		static std::string buildPath(INFO info);
	protected:
	private:
		std::string m_graphicalResources;
		std::string m_configfiles;
		std::string m_pluginsConfig;
};

#endif // APPCONFIG_H
