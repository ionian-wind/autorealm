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

#include <utils/utils.h>

template <class T>
Composite<T>::Composite(boost::filesystem::path const &location)
:Component<T>(findConfigurationFile(location)), m_components()
{
	///\pre location must exists
	if(!boost::filesystem::exists(location))
		throw std::runtime_error("Given location does not exists");

	///\pre location is a directory
	if(!boost::filesystem::is_directory(location))
		throw std::runtime_error("Given location is not a directory");


	const boost::filesystem::path toSkip(findConfigurationFile(location)); //skip the file with same name as directory

	for(auto content = boost::filesystem::directory_iterator(location); content != boost::filesystem::directory_iterator(); ++content)
	{
		if(toSkip == content->path())
			continue;

		if(boost::filesystem::is_regular_file(content->path()))
			m_components.push_back(new Component<T>(content->path()));
		else
			m_components.push_back(new Composite<T>(content->path()));
	}
}

template <class T>
Composite<T>::~Composite() throw()
{
	for(Component<T>* i:m_components)
		delete i;
}

template <class T>
void Composite<T>::create(void)
{
	create(nullptr);
}

template <class T>
void Composite<T>::create(T *parent)
{
	T::create(parent, Component<T>::getName());

	for(T* i : m_components)
		if(typeid(*i) == typeid(Composite<T>))
			static_cast<Composite<T>*>(i)->create(this);
		else
			i->T::create(this, i->getName());
}

template <class T>
typename Composite<T>::MenuIter Composite<T>::begin(void)
{
	return MenuIter::begin_of(this);
}

template <class T>
typename Composite<T>::MenuIter Composite<T>::end(void)
{
	return MenuIter::end_of(this);
}
