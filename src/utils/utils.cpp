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

#include "utils.h"

#include <wx/image.h>

#ifdef WIN32
#define HOME "HOMEPATH" ///\todo check that it should not be %APPDATA% instead of %HOMEPATH%
#else
#define HOME "HOME"
#endif

#include <boost/filesystem.hpp>

namespace fs=boost::filesystem;

wxBitmap loadImage(std::string const &fileName)
{
	if(fileName.empty())
		return wxNullBitmap;

	return wxBitmap(wxImage(AppConfig::buildPath(AppConfig::INFO::GRP_RES) + fileName));
}

std::string getUserConfigDir(void)
{
	///\todo find a better solution to follow freeDesktop.org's recommmandations
	std::string homepath(getenv(HOME));///\note flawfinder say I should use getenv with care


	const fs::path usualUserConfig(homepath + "/.autorealm/config");
	if(fs::exists(usualUserConfig))
		return usualUserConfig.string();

	const fs::path xdgUserConfig(homepath + "/.config/autorealm/config");
	if(fs::exists(xdgUserConfig))
		return xdgUserConfig.string();
	return std::string();
}

std::string getSystemConfigDir(void)
{
	#ifdef WIN32
		throw std::logic_error("System configuration folder detection unimplemented on Windows");
	#endif

	const fs::path systemConfFile="/usr/local/etc/autorealm/config"; ///\todo make this constant a #define to allow compile-time definition
	if(fs::exists(systemConfFile))
		return systemConfFile.string();
	throw std::runtime_error("Unable to find system-wide configuration file:\n\""+systemConfFile.string()+"\"");
}
