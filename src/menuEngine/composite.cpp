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

#include "composite.h"

#include <assert.h>

#include <utils/textfile.h>

#include "leaf.h"
#include "iterator.h"

Composite::Composite(boost::filesystem::path const &location)
:m_components()
{
	//!\pre location must exists
	if(!boost::filesystem::exists(location))
		throw std::runtime_error("Given location does not exists");
	//!\pre location is a directory
	if(!boost::filesystem::is_directory(location))
		throw std::runtime_error("Given location is not a directory");

	auto file=TextFile::OpenFile(findConfigurationFile(location));
	loadConfiguration(file);
}

boost::filesystem::path Composite::findConfigurationFile(boost::filesystem::path const &location)
{
	boost::filesystem::path file(location.string()+"/"+location.filename().string());
	if(!boost::filesystem::exists(file))
		throw std::runtime_error("configuration file is missing");
	return file;
}

void Composite::buildMenu(boost::filesystem::path const &location)
{
	const boost::filesystem::path toSkip(findConfigurationFile(location)); //skip the file with same name as directory
	for(auto content=boost::filesystem::directory_iterator(location);content!=boost::filesystem::directory_iterator();++content)
	{
		if(toSkip==content->path())
			continue;
		m_components.push_back(std::unique_ptr<Component>());
		if(boost::filesystem::is_regular_file(content->path()))
			m_components.back().reset(new Leaf(TextFile::OpenFile(content->path())));
		else
		{
			Composite *m(new Composite(content->path()));
			m->buildMenu(content->path());
			m_components.back().reset(m);
		}
	}
}

void Composite::create(void)
{
	create(nullptr);
}

void Composite::create(MenuConverter* parent)
{
	MenuConverter::create(parent);
	for(auto &i:m_components)
		i->create(this);
}

Iterator<Composite> Composite::begin(void)
{
	return Iterator<Composite>(this);
}

Composite::MenuIter Composite::end(void)
{
	return MenuIter(this, false);
}
