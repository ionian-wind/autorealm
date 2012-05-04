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

template <class Composite>
Iterator<Composite>& Iterator<Composite>::operator++(void)
{
	++m_position;
	goDeeper();
	return *this;
}

template <class Composite>
Iterator<Composite>::Iterator(Composite *owner)
:m_owner(owner),m_position(owner->m_components.begin())
{
	goDeeper();
}

template <class Composite>
Iterator<Composite>::Iterator(Composite *owner, bool dumb)
:m_owner(owner),m_position(owner->m_components.end())
{
	goUpper();
}

template <class Composite>
bool Iterator<Composite>::operator!=(Iterator<Composite> const&other)const
{
	return m_owner!=other.m_owner || (*m_position)!=(*other.m_position);
}

template <class Composite>
//decltype(*Iterator<Composite>::m_position) Iterator<Composite>::operator->(void)
Component* Iterator<Composite>::operator->(void)
{
	return m_position->get();
}

template <class Composite>
Component& Iterator<Composite>::operator*(void)
{
	return *(m_position->get());
}

template <class Composite>
void Iterator<Composite>::goDeeper(void)
{
	//!\pre m_owner is a valid Composite
	//!\post m_position refer to a leaf or Iterator is set to end()
	//!\post m_owner is a valid Composite but might have changed
	if(m_owner->m_components.empty() || isEndOfLevel())
		goUpper();
	else if(isComposite())
	{
		m_ancestors.push(std::make_pair(m_owner,m_position));
		m_owner=static_cast<Composite*>(m_position->get());
		m_position=m_owner->m_components.begin();
		goDeeper();
	}
}

template <class Composite>
void Iterator<Composite>::goUpper(void)
{
	if(isEndOfLevel() && !m_ancestors.empty())
	{
		m_owner=m_ancestors.top().first;
		m_position=m_ancestors.top().second;
		m_ancestors.pop();
		operator++();
		goUpper();
	}
}

template <class Composite>
bool Iterator<Composite>::isComposite(void)const
{
	return typeid(*m_position->get())==typeid(Composite);
}

template <class Composite>
bool Iterator<Composite>::isEndOfLevel(void)const
{
	return m_position==m_owner->m_components.end();
}
