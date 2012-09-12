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

#include "singleton.h"
#include "id.h"
#include <utils/textfile.h>

class AppConfig: public Singleton<AppConfig>
{
public:
	typedef std::vector<std::string> TagList;
private:
	std::string m_datas;
	static const uint16_t sc_nbDefaultRenderers=2; ///\note 2 for filler and border
	TagList m_defaultRendererTags[sc_nbDefaultRenderers];
	TextFile m_rootConfigFile;
public:
	enum RENDERER {BORDER=0, FILLER, LASTRENDERER};
	enum INFO {GRP_RES = 0, PLUGINS, MENU, LASTINDEX};
	/** \brief retrieve data from a configuration file */
	AppConfig(void);
	/**	\brief retrieve the needed path from stored datas
	 *	Stored datas are read from file config. It's location depends on your OS
	 *	\param INFO name of the data to retrieve
	 */
	static std::string buildPath(INFO info);
	static TagList getRenderer(RENDERER renderer);
private:
	std::string throwCorrupted(void)const throw();
};

#endif // APPCONFIG_H
