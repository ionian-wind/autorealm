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
	boost::filesystem::path configDir;
	// guess the directory where configuration is stored
	//!\todo use freedesktop.org recommmandations for linux, and fallback on system variables if they are not supported on client computer
	std::unique_ptr<TextFile> rootConfigFile;
#ifdef WIN32
	std::string homepath(getenv("HOMEPATH")); //!\todo check that it should not be %APPDATA% instead of %HOMEPATH%
#else
	std::string homepath(getenv("HOME"));
#endif
	if(boost::filesystem::exists(homepath+"/.autorealm"))
		configDir=boost::filesystem::path(homepath+".autorealm/");
	else if(boost::filesystem::exists(homepath+"/.config/autorealm"))
		configDir=boost::filesystem::path(homepath+"/.config/autorealm/");

	// read global configuration
	rootConfigFile=TextFile::OpenFile(boost::filesystem::path(configDir.string()+"config"));

	for(uint8_t i=GRP_RES;i<LASTINDEX && !rootConfigFile->eofReached();++i)
		readLine(rootConfigFile);
}

std::string AppConfig::buildPath(INFO info)
{
	return GetInstance().m_datas[info];
}

void AppConfig::readLine(std::unique_ptr<TextFile> &file)
{
	m_datas.push_back(file->readLine());
//!\todo find a way to control that files in configuration truly exists (but in another method)
//	if(!boost::filesystem::exists(m_rootconfig.string()+m_datas.back()))
//		throw std::runtime_error("Entry "+m_datas.back()+"specified in configuration file does not exists.");
}
