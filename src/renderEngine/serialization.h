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

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <pluginEngine/renderer.h>
#include <pluginEngine/drawerlist.h>


#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>

#include "group.h"
#include "shape.h"
#include "vertex.h"
#include "color.h"
#include <gui/app.h>

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Render::Object);

BOOST_CLASS_EXPORT(Render::Group);
BOOST_CLASS_EXPORT(Render::Shape);
BOOST_CLASS_EXPORT(Render::Object);

//#define SERIALIZATION_WITHOUT_RENDERER

//////////////////////////////////////
//              Renderer            //
//////////////////////////////////////

template<typename Archive>
void serializeRenderer(Archive &ar, std::unique_ptr<Renderer> &object)
{
#ifndef SERIALIZATION_WITHOUT_RENDERER
	//save
	if(!object)///\todo refactor this code to avoid using a dumb Renderer instance
		/**currently, this dumb instance is needed because I choosed to use a function
		instead of the boost::serialization true system for Renderer. The Boost
		system would have allowed me to split the save/load work for Renderer but
		it does not (or I did not find how to) allow to serialize stuff unknown by
		the serializer/deserializer
		**/
	{
		Renderer &tmp=(*DrawerList::GetInstance().m_drawerList[0]);
		Renderer *tmp2=tmp.clone();
		object.reset(tmp2);
	}
	std::string str=static_cast<std::string>(*object);
	ar & str;

	size_t p1(str.find_first_of('(')),p2(str.find_last_of(')'));
	std::string tag=str.substr(0,p1);
	std::string data=str.substr(p1+1,p2-p1);///\todo implement checks

	for(Drawer *i:DrawerList::GetInstance().m_drawerList)
	{
		if((*i)==tag)
			object.reset(i->create(data));
	}

#endif
}

namespace Render
{

//////////////////////////////////////
//              Drawable            //
//////////////////////////////////////
template<typename Archive>
void Drawable::serialize(Archive & ar, const unsigned int version)
{
}

//////////////////////////////////////
//              Vertex              //
//////////////////////////////////////
template<class Archive>
void Vertex::serialize(Archive &ar, const unsigned int version)
{
	serializeRenderer(ar,m_renderer);
	ar & m_point;
}

//////////////////////////////////////
//              Group               //
//////////////////////////////////////
template<class Archive>
void Group::serialize(Archive &ar, const unsigned int version)
{
	ar & boost::serialization::base_object<Render::Object>( *this );
	ar.register_type(static_cast<Render::Group*>(nullptr));
	ar.register_type(static_cast<Render::Shape*>(nullptr));
	ar &m_children;
}

//////////////////////////////////////
//              Shape               //
//////////////////////////////////////
template<class Archive>
void Shape::serialize(Archive &ar, const unsigned int version)
{
	ar & ::boost::serialization::base_object<Object>( *this );
	ar & m_children;
	serializeRenderer(ar,m_filler);
	ar & m_close;
}

//////////////////////////////////////
//              Point               //
//////////////////////////////////////
template<class Archive>
void Point::serialize(Archive &ar, const unsigned int version)
{
	ar &m_x;
	ar &m_y;
	ar &m_z;
}

//////////////////////////////////////
//              Color               //
//////////////////////////////////////
template<class Archive>
void Color::serialize(Archive &ar, const unsigned int version)
{
	ar &m_red;
	ar &m_green;
	ar &m_blue;
	ar &m_alpha;
}

//////////////////////////////////////
//              Object              //
//////////////////////////////////////
template<class Archive>
void Object::serialize(Archive &ar, const unsigned int version)
{
	ar & boost::serialization::base_object<Drawable>(*this);
}

}

#endif
