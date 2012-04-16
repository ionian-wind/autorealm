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

#include <utils/textfile.h>

AppConfig::AppConfig()
{
	// guess the directory where configuration is stored
	//!\todo use freedesktop.org recommmandations for linux, and fallback on system variables if they are not supported on client computer
	std::unique_ptr<TextFile> rootConfigFile;
	if(boost::filesystem::exists("/home/berenger/.autorealm"))
		m_rootconfig=boost::filesystem::path("/home/berenger/.autorealm/");
	else if(boost::filesystem::exists("/home/berenger/.config/autorealm"))
		m_rootconfig=boost::filesystem::path("/home/berenger/.config/autorealm/");

	// read global configuration
	rootConfigFile=TextFile::OpenFile(boost::filesystem::path(m_rootconfig.string()+"config"));

	m_graphicalResources=rootConfigFile->readLine();
	m_pluginsConfig=rootConfigFile->readLine();
	if(!(boost::filesystem::exists(m_rootconfig.string()+m_graphicalResources) && boost::filesystem::exists(m_rootconfig.string()+m_pluginsConfig)))
//		|| !boost::filesystem::exists(m_splashImage)
//		|| !boost::filesystem::exists(m_pluginsConfig))
		throw std::runtime_error("Configuration file invalid");
}

std::string AppConfig::buildPath(INFO info)
{
	std::string result(GetInstance().m_rootconfig.string());
	switch(info)
	{
	case GRP_RES:
		return result+GetInstance().m_graphicalResources;
	case PLUGINS:
		return result+GetInstance().m_pluginsConfig;
	default:
		return "";
	}
}
