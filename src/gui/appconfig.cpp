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
	fillList(m_datas,GRP_RES, LASTINDEX);
	fillList(m_defaultRendererTags,BORDER, LASTRENDERER);
}

std::string AppConfig::buildPath(INFO info)
{
 	assert(LASTINDEX>=info);
	return GetInstance().m_datas[info];
}

Render::TagList AppConfig::getRenderer(RENDERER renderer)
{
	assert(LASTRENDERER>=renderer);
	return GetInstance().m_defaultRendererTags[renderer];
}

template <typename LIST, typename INDEX>
void AppConfig::fillList(LIST &list,INDEX min, INDEX max)
{
	uint8_t i=min;
	for(;max>=i && !m_rootConfigFile.eofReached();++i)
		list[i]=m_rootConfigFile.readLine();
	if(max>=i)
		throw std::runtime_error("Configuration file "+m_rootConfigFile.getFileName()+" corrupted");
}
