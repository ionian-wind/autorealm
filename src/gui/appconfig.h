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

#include <boost/filesystem.hpp>

#include "singleton.h"
#include <utils/textfile.h>

class AppConfig:public Singleton<AppConfig>
{
	std::vector<std::string> m_datas;
public:
	enum INFO{GRP_RES=0, PLUGINS=1, SPLASH=2, MENU=3, LASTINDEX};
	/** \brief retrieve data from a configuration file */
	AppConfig();
	/**	\brief retrieve the needed path from stored datas
	 *	Stored datas are read from file config. It's location depends on your OS
	 *	\param INFO name of the data to retrieve
	 */
	static std::string buildPath(INFO info);
protected:
    /** \brief Read a line from the given file and store it into m_data
     *	\pre file must be valid
     *	\param file std::unique_ptr<TextFile>& file from which datas must be read
     *	\post m_data have one more element containing the read file
     *	\post file's cursor's position have moved and might be invalid (end of file by example)
     */
	void readLine(std::unique_ptr<TextFile> &file);
};

#endif // APPCONFIG_H
