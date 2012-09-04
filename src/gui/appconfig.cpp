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

#include "appconfig.h"

#include <utils/textfile.h>

#include "utils/utils.h"

AppConfig::AppConfig()
{
	// guess the directory where configuration is stored
	TextFile rootConfigFile(TextFile::OpenFile(getPosixConfDir(), "config"));

	for(uint8_t i = GRP_RES; LASTINDEX>i && !rootConfigFile.eofReached(); ++i)
		m_datas.push_back(rootConfigFile.readLine());
	if(LASTINDEX>i)
		throw std::runtime_error("Configuration file "+rootConfigFile.getFileName()+" corrupted");
}

std::string AppConfig::buildPath(INFO info)
{
	return GetInstance().m_datas[info];
}
