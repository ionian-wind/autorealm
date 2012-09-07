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

#ifndef OBJECT_H
#define OBJECT_H

class Mutator;

#include <boost/serialization/access.hpp>

#include "drawable.h"

namespace Render
{

/** \brief Ancestor of Shape and Group. It only provides an interface for composite and visitor patterns */
class Object: public Drawable
{
	friend class boost::serialization::access;
public:
	/** \brief apply an algorithm on the object
	 *	\param v Mutator& algo to apply
	 */
	virtual void accept(Mutator &v) = 0;
	virtual ~Object(void) throw() = default;
	virtual Object* clone(void)const override =0;
private:
//	template<class Archive>
//	void serialize(Archive &ar, const unsigned int version);
};

inline Object* new_clone( const Object& r )
{
	return r.clone();//should assert that typeid(*r.clone())==typeid(r)
}

inline Object* new_clone( const Object* r )
{
	return r ? r->clone() : 0;
}

}

#endif // OBJECT_H
