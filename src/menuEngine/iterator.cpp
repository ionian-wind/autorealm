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

template <class T>
Iterator<T> &Iterator<T>::operator++(void)
{
	++m_position;
	goDeeper();
	return *this;
}

template <class T>
Iterator<T>::Iterator(Iterator<T> const &other) = default;
//:m_owner(other.m_owner), m_position(other.m_position), m_ancestors(other.m_ancestors)
//{
//}

template <class T>
Iterator<T> &Iterator<T>::operator=(Iterator<T> const &other)
{
	Iterator<T> me(other);
	std::swap(me, *this);
	return *this;
}

template <class T>
Iterator<T> Iterator<T>::begin_of(Composite<T> *owner)
{
	Iterator<T> *it = new Iterator<T>(owner);
	it->m_position = owner->m_components.begin();
	it->goDeeper();
	return *it;
}

template <class T>
Iterator<T> Iterator<T>::end_of(Composite<T> *owner)
{
	Iterator<T> *it = new Iterator<T>(owner);
	it->m_position = owner->m_components.end();
	it->goUpper();
	return *it;
}

template <class T>
Iterator<T>::Iterator(Composite<T> *owner)
	: m_owner(owner)
{
}

template <class T>
bool Iterator<T>::operator!=(Iterator<T> const &other)const
{
	return (m_owner != other.m_owner) || (m_position != other.m_position);
}

template <class T>
Component<T> *Iterator<T>::operator->(void)
{
	return m_position->get();
}

template <class T>
Component<T> &Iterator<T>::operator*(void)
{
	return *(m_position->get());
}

template <class T>
void Iterator<T>::goDeeper(void)
{
	//!\pre m_owner is a valid Composite<T>
	//!\post m_position refer to a leaf or Iterator is set to end()
	//!\post m_owner is a valid Composite<T> but might have changed
	if(m_owner->m_components.empty() || isEndOfLevel())
		goUpper();
	else if(isComposite())
	{
		m_ancestors.push(std::make_pair(m_owner, m_position));
		m_owner = static_cast<Composite<T>*>(m_position->get());
		m_position = m_owner->m_components.begin();
		goDeeper();
	}
}

template <class T>
void Iterator<T>::goUpper(void)
{
	if(isEndOfLevel() && !m_ancestors.empty())
	{
		m_owner = m_ancestors.top().first;
		m_position = m_ancestors.top().second;
		m_ancestors.pop();
		operator++();
		goUpper();
	}
}

template <class T>
bool Iterator<T>::isComposite(void)const
{
	return typeid(*m_position->get()) == typeid(Composite<T>);
}

template <class T>
bool Iterator<T>::isEndOfLevel(void)const
{
	return m_position == m_owner->m_components.end();
}
