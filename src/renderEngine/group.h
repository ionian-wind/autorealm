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

#ifndef GROUP_H
#define GROUP_H

#include "object.h"

#include <boost/ptr_container/serialize_ptr_vector.hpp>

namespace Render
{
class Group : public Object
{
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar,const unsigned int version);
public:
	~Group(void)throw();

	/** \brief apply on algorithm on the group and it's children
	 *
	 *	\param v Mutator& object wich contain the algorithm to apply
	 *	\pre all children contain a valid pointer on an object
	 */
	virtual void accept(Mutator &v);
	/** \brief draw the group and everything it contains
	 *	\throw nothing
	 */
	void draw(void)const throw();

	/** \brief move the given element into a new element of children
	 *
	 *	\param target Object* pointer to data which will be transmitted
	 *	\pre target must contain a valid pointer on an object
	 *	\post target is no longer usable
	 *	\post m_children size has increased
	 *	\post last element of m_children contain the pointer target
	 *	\throw can throw if there not enough memory to create the new element. If so, target is not changed and an exception is thrown to inform caller of the problem.
	 */
	void push_back(Object const& target);

	virtual Object* clone(void)const override;

public:
protected:
	typedef boost::ptr_vector<Object> ObjectList;///\todo check if objects are freed
	ObjectList m_children;
private:
};

}

#endif // GROUP_H
