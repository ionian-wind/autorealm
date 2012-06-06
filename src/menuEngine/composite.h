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

//#include "component.h"
//#include "iterator.h"

template <class T>
class Component: public T
{
	public:
		std::string getPluginName(void)const;
		virtual ~Component()=default;
		std::string getName(void)const;
		void disable(bool disable=true);
		bool isEnabled(void)const;
	protected:
		void virtual loadConfiguration(std::unique_ptr<TextFile> &file);
	private:
		std::string m_name;
		bool m_enable=true;
};

template <class Compositor, class TComponent>
class Iterator
{
	friend Compositor;
public:
	Iterator& operator++(void);
	bool operator!=(Iterator<Compositor,TComponent> const&other)const;

//	Component<TComponent>* operator->(void);
//	Component<TComponent>& operator*(void);
	TComponent* operator->(void);
	TComponent& operator*(void);
	bool isEndOfLevel(void)const;
protected:
	Iterator(Compositor *owner);
	Iterator(Compositor *owner, bool dumb);//!\todo make Ctor private and create static methods to build begin/end iterators
	void goDeeper();
	void goUpper();
	bool isComposite(void)const;
private:
	Compositor *m_owner;
	typename Compositor::Components::iterator m_position;
	std::stack<std::pair<Compositor*,typename Compositor::Components::iterator>> m_ancestors;
};

template <class T>
class Composite : public Component<T>
{
	typedef class Iterator<Composite<T>,Component<T>> MenuIter;
	friend MenuIter;
	typedef std::vector<std::unique_ptr<Component<T>>> Components;
public:
	Composite(boost::filesystem::path const &location);
	virtual ~Composite()=default;
	void buildMenu(boost::filesystem::path const &location);
	virtual void create(void);
	MenuIter begin(void);
	MenuIter end(void);
protected:
	boost::filesystem::path findConfigurationFile(boost::filesystem::path const &location);
	virtual void create(T* parent);
private:
public:
protected:
	Components m_components;
private:
};

template <class T>
class Leaf : public Component<T>
{
friend class Composite<T>;
public:
	virtual ~Leaf()=default;
protected:
	Leaf(std::unique_ptr<TextFile> file){Component<T>::loadConfiguration(file);}
};

#include "iterator.cpp"
#include "composite.cpp"
#include "component.cpp"

#endif
