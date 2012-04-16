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
	std::string homepath("/home/berenger/");
	if(boost::filesystem::exists(homepath+"/.autorealm"))
		m_rootconfig=boost::filesystem::path(homepath+".autorealm/");
	else if(boost::filesystem::exists(homepath+".config/autorealm"))
		m_rootconfig=boost::filesystem::path(homepath+".config/autorealm/");

	// read global configuration
	rootConfigFile=TextFile::OpenFile(boost::filesystem::path(m_rootconfig.string()+"config"));

	readLine(rootConfigFile);
	readLine(rootConfigFile);
}

std::string AppConfig::buildPath(INFO info)
{
	std::string result(GetInstance().m_rootconfig.string());
	return result+GetInstance().m_datas[info];
}

void AppConfig::readLine(std::unique_ptr<TextFile> &file)
{
	m_datas.push_back(file->readLine());
	if(!boost::filesystem::exists(m_rootconfig.string()+m_datas.back()))
		throw std::runtime_error("Entry "+m_datas.back()+"specified in configuration file does not exists.");
}
