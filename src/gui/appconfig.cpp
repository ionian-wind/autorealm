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

AppConfig::AppConfig(void)
:m_datas(),m_defaultRendererTags(),m_rootConfigFile(TextFile::OpenFile(getPosixConfDir(), "config"))
{
	uint8_t i;
	for(i = GRP_RES; LASTINDEX>=i && !m_rootConfigFile.eofReached(); ++i)
		m_datas.push_back(m_rootConfigFile.readLine());
	if(LASTINDEX>i)
		throw std::runtime_error(throwCorrupted());

	for(i = 0; LASTRENDERER>=i && !m_rootConfigFile.eofReached();++i)
		m_defaultRendererTags[i]=m_rootConfigFile.readLine();

	if(LASTRENDERER>=i)
		throw std::runtime_error(throwCorrupted());
}

std::string AppConfig::buildPath(INFO info)
{
 	assert(LASTINDEX>=info);
	return GetInstance().m_datas[info];
}

std::string AppConfig::getRenderer(RENDERER renderer)
{
	assert(LASTRENDERER>=renderer);
	return GetInstance().m_defaultRendererTags[renderer];
}

std::string AppConfig::throwCorrupted(void)const throw()
{
	return std::string("Configuration file "+m_rootConfigFile.getFileName()+" corrupted");
}
