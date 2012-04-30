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

#ifndef ITERATOR_H
#define ITERATOR_H

class Menu;

template <class Composite>
class Iterator
{
	friend class Menu;
public:
	Iterator& operator++(void);
	bool operator!=(Iterator<Composite> const&other)const;
	//implémenter les opérateurs de déréférencement tel un smart ptr
protected:
	Iterator(Composite *owner);
	Iterator(Composite *owner, bool dumb);
private:
	Composite *m_owner;
	typename Composite::Components::iterator m_position;
	std::stack<std::pair<Composite*,typename Composite::Components::iterator>> m_ancestors;
};

#include "iterator.cpp"
#endif // ITERATOR_H
