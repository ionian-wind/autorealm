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

template <class Compositor, class TComponent>
Iterator<Compositor, TComponent>& Iterator<Compositor, TComponent>::operator++(void)
{
	++m_position;
	goDeeper();
	return *this;
}

template <class Compositor, class TComponent>
Iterator<Compositor, TComponent>::Iterator(Compositor *owner)
:m_owner(owner),m_position(owner->m_components.begin())
{
	goDeeper();
}

template <class Compositor, class TComponent>
Iterator<Compositor, TComponent>::Iterator(Compositor *owner, bool dumb)
:m_owner(owner),m_position(owner->m_components.end())
{
	goUpper();
}

template <class Compositor, class TComponent>
bool Iterator<Compositor, TComponent>::operator!=(Iterator<Compositor, TComponent> const&other)const
{
	return (m_owner!=other.m_owner) || (m_position!=other.m_position);
}

template <class Compositor, class TComponent>
//Component<TComponent>* Iterator<Compositor, TComponent>::operator->(void)
TComponent* Iterator<Compositor, TComponent>::operator->(void)
{
	return m_position->get();
}

template <class Compositor, class TComponent>
//Component<TComponent>& Iterator<Compositor, TComponent>::operator*(void)
TComponent& Iterator<Compositor, TComponent>::operator*(void)
{
	return *(m_position->get());
}

template <class Compositor, class TComponent>
void Iterator<Compositor, TComponent>::goDeeper(void)
{
	//!\pre m_owner is a valid Compositor
	//!\post m_position refer to a leaf or Iterator is set to end()
	//!\post m_owner is a valid Compositor but might have changed
	if(m_owner->m_components.empty() || isEndOfLevel())
		goUpper();
	else if(isComposite())
	{
		m_ancestors.push(std::make_pair(m_owner,m_position));
		m_owner=static_cast<Compositor*>(m_position->get());
		m_position=m_owner->m_components.begin();
		goDeeper();
	}
}

template <class Compositor, class TComponent>
void Iterator<Compositor, TComponent>::goUpper(void)
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

template <class Compositor, class TComponent>
bool Iterator<Compositor, TComponent>::isComposite(void)const
{
	return typeid(*m_position->get())==typeid(Compositor);
}

template <class Compositor, class TComponent>
bool Iterator<Compositor, TComponent>::isEndOfLevel(void)const
{
	return m_position==m_owner->m_components.end();
}
