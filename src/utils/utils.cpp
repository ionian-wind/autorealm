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

#include "utils.h"

#include <wx/image.h>

#include "../pluginEngine/container.h"
#include "../gui/MainFrame.h"

/** \brief retrieve a line from a text file
 * \todo use locales?
 * \todo use wide characters? (aka unicode)
 * \todo replace with something more standard if any
 * \param source FILE*
 * \return std::string
 *
 */
std::string readline(FILE *source)
{
	std::string result;
	char c;
	do
	{
		result.push_back(fgetc(source));
		c=result.back();
	}
	while(!feof(source) && c!='\n' && c!='\r');//!\note with those 2 characters, we should be fine on Mac OSand Linux operating systems. Problems will probably happens with MS Windows, because end of lines there are "\r\n" or "\n\r"
	result.resize(result.size()-1);

	return result;
}

bool eofReached(FILE *source)
{
	long int current_pos=ftell(source);
	bool result=true;

	fseek(source,0,SEEK_END);
	result=current_pos==ftell(source);
	fseek(source,current_pos,SEEK_SET);
	return result;
}

wxBitmap loadImage(std::string const & fileName)
{
	if(fileName.empty())
		return wxNullBitmap;
	return wxBitmap(wxImage(AppConfig::buildPath(AppConfig::INFO::GRP_RES)+fileName));
}
