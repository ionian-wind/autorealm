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
#include <memory>
#include <string>

#include <boost/filesystem.hpp>

#include <utils/textfile.h>

template <class T> class Composite;

template <class T>
class Component: public T //!\todo change the relation to have something which behave more like STL containers
{
	public:
		std::string getPluginName(void)const;
		virtual ~Component() throw() =default;
		std::string getName(void)const;
		void disable(bool disable=true);
		bool isEnabled(void)const;
	protected:
		void virtual loadConfiguration(std::unique_ptr<TextFile> &file);
	private:
		std::string m_name;
		bool m_enable=true;
};

template <class T>
class Iterator
{
	friend Composite<T>;
public:
	Iterator& operator++(void);
	bool operator!=(Iterator<T> const&other)const;
	Iterator<T>& operator=(Iterator<T> const& other);
	Iterator(Iterator<T> const& other);

	Component<T>* operator->(void);
	Component<T>& operator*(void);
	bool isEndOfLevel(void)const;
protected:
	void goDeeper();
	void goUpper();
	bool isComposite(void)const;
private:
	Iterator(Composite<T> *owner);
	static Iterator<T> begin_of(Composite<T> *owner);
	static Iterator<T> end_of(Composite<T> *owner);

private:
	Composite<T> *m_owner;
	typename Composite<T>::Components::iterator m_position;
	std::stack<std::pair<Composite<T>*,typename Composite<T>::Components::iterator>> m_ancestors;
};

template <class T>
class Composite : public Component<T>
{
public:
	typedef class Iterator<T> MenuIter;
	friend MenuIter;
protected:
	typedef std::vector<std::unique_ptr<Component<T>>> Components;
	Components m_components;
private:

public:
	Composite(boost::filesystem::path const &location);
	virtual ~Composite() throw() =default;
	void buildMenu(boost::filesystem::path const &location);
	virtual void create(void);
	MenuIter begin(void);
	MenuIter end(void);
protected:
	boost::filesystem::path findConfigurationFile(boost::filesystem::path const &location);
	virtual void create(T* parent);
private:

};

template <class T>
class Leaf : public Component<T>
{
friend class Composite<T>;
public:
	virtual ~Leaf() throw() =default;
protected:
	Leaf(std::unique_ptr<TextFile> file){Component<T>::loadConfiguration(file);}
};

#include <assert.h>
#include <utils/textfile.h>

#include "iterator.cpp"
#include "composite.cpp"
#include "component.cpp"

#endif
