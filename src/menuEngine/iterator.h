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

#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator
{
	friend Composite<T>;
public:
	Iterator &operator++(void);
	bool operator!=(Iterator<T> const &other)const;
	Iterator<T> &operator=(Iterator<T> const &other);
	Iterator(Iterator<T> const &other);

	Component<T> *operator->(void);
	Component<T> &operator*(void);
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
	std::stack<std::pair<Composite<T>*, typename Composite<T>::Components::iterator>> m_ancestors;
};

#include "iterator.cpp"
#endif // ITERATOR_H
