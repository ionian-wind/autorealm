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

#ifndef RENDERER_H
#define RENDERER_H

#include <boost/serialization/access.hpp>
#include "drawer.h"

class Renderer
{
	friend class ::boost::serialization::access;
	template<typename Archive>
	void serialize(Archive & ar, const unsigned int version);
	virtual std::string const getData(void)const=0;
public:
	Drawer *m_parent=nullptr; ///associated parent (for tags)
	Renderer(void)throw()=default;

	virtual void init(std::string const& str)=0;
	virtual void render(void)const throw()=0;
	virtual Renderer* clone(void)const=0;
	operator std::string(void)const
	{
		return m_parent->getTags()+"("+getData()+")";
	}
};

#endif
