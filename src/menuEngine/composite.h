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

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

#include <boost/filesystem.hpp>
#include <utils/textfile.h>

template <class T> class Composite;

#include "component.h"
#include "iterator.h"

template <class T>
class Composite : public Component<T>
{
public:
	typedef class Iterator<T> MenuIter;
	friend MenuIter;
protected:
	typedef std::vector<Component<T>*> Components;
	Components m_components;
private:

public:
	Composite(boost::filesystem::path const &location);
	virtual ~Composite() throw();
	virtual void create(void);
	MenuIter begin(void);
	MenuIter end(void);
protected:
	virtual void create(T *parent);
private:

};

#include "composite.cpp"

#endif
