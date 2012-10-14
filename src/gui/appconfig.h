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
#include <utils/utils.h>
#include <utils/textfile.h>
#include <renderEngine/taglist.h>

#include "singleton.h"
#include "id.h"

class AppConfig: public Singleton<AppConfig>
{
public:
	enum RENDERER {BORDER=0, FILLER, LASTRENDERER=FILLER};
	enum INFO {GRP_RES = 0, PLUGINS, MENU, LASTINDEX=MENU};
	/** \brief retrieve data from a configuration file */
	AppConfig(void);
	/**	\brief retrieve the needed path from stored datas
	 *	Stored datas are read from file config. It's location depends on your OS
	 *	\param INFO name of the data to retrieve
	 */
	static std::string buildPath(INFO info);
	static Render::TagList getRenderer(RENDERER renderer);
private:
	std::string throwCorrupted(void)const throw();
	template <typename LIST, typename INDEX>
	void fillList(LIST &list,INDEX min, INDEX max);
private:
	typedef std::string PathList;
	PathList m_datas[LASTINDEX+1];
	Render::TagList m_defaultRendererTags[LASTRENDERER+1];
	TextFile m_rootConfigFile;
};

#endif // APPCONFIG_H
