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

wxBitmap loadImage(std::string const &fileName)
{
	if(fileName.empty())
		return wxNullBitmap;

	return wxBitmap(wxImage(AppConfig::buildPath(AppConfig::INFO::GRP_RES) + fileName));
}

std::string getPosixConfDir(void)
{
	///\todo find a better solution to follow freeDesktop.org's recommmandations
	std::string homepath(getenv("HOME"));///\note flawfinder say I should use getenv with care

	if(boost::filesystem::exists(homepath + "/.autorealm"))
		return boost::filesystem::path(homepath + ".autorealm/").string();
	else if(boost::filesystem::exists(homepath + "/.config/autorealm"))
		return boost::filesystem::path(homepath + "/.config/autorealm/").string();

#ifndef WIN32
	else if(boost::filesystem::exists("/etc/autorealm"))
		return boost::filesystem::path("/etc/autorealm").string();

#endif
	throw std::runtime_error("configuration not found");
}

boost::filesystem::path findConfigurationFile(boost::filesystem::path const &location)
{
	boost::filesystem::path file(location.string() + "/" + location.filename().string());

	if(!boost::filesystem::exists(file))
		throw std::runtime_error("configuration file is missing");

	return file;
}

///\todo implement it fully
Render::TagList makeTagList(std::string const& line)
{
	return line;
}
