/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU Lesser General Public License as published by        *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU Lesser General Public License for more details.                                *
 *                                                                                *
 *    You should have received a copy of the GNU Lesser General Public License           *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

#ifndef ITERATOR_H
#define ITERATOR_H

template <class Compositor>
class Iterator
{
	friend Compositor;
public:
	Iterator& operator++(void);
	bool operator!=(Iterator<Compositor> const&other)const;

	Component* operator->(void);
	Component& operator*(void);
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

#include "iterator.cpp"
#endif // ITERATOR_H
