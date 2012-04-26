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

#include "menu.h"

#include <assert.h>
#include "item.h"

Menu::Menu(boost::filesystem::path const &location)
:Menu(location,nullptr)
{
}

Menu::Menu(boost::filesystem::path const &location, MenuItem* parent)
{
	//!\pre location must exists
	if(!boost::filesystem::exists(location))
		throw std::runtime_error("Given location does not exists");
	//!\pre location is a directory
	if(!boost::filesystem::is_directory(location))
		throw std::runtime_error("Given location is not a directory");

	init(findConfigurationFile(location),parent);
	buildMenu(location);
}

boost::filesystem::path Menu::findConfigurationFile(boost::filesystem::path const &location)
{
	boost::filesystem::path file(location.string()+"/"+location.filename().string());
	if(!boost::filesystem::exists(file))
		throw std::runtime_error("configuration file is missing");
	return file;
}

void Menu::buildMenu(boost::filesystem::path const &location)
{
	const boost::filesystem::path toSkip(findConfigurationFile(location)); //skip the file with same name as directory
	for(auto content=boost::filesystem::directory_iterator(location);content!=boost::filesystem::directory_iterator();++content)
	{
		if(boost::filesystem::is_regular_file(content->path()))
		{
			if(toSkip!=content->path())
				m_leaves.push_back(std::unique_ptr<MenuItem>(new Item(content->path(),this)));
		}
		else
			m_leaves.push_back(std::unique_ptr<MenuItem>(new Menu(content->path(),this)));
	}
}
