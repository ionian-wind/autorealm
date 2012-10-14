#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <pluginEngine/renderer.h>

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
	//old style
//	ar.register_type(static_cast<Renderer*>(nullptr));
//	Renderer *tmp=object.release();
//	ar & tmp;
//	object.reset(tmp);

	//new style
	//save
	std::string str=*object;
	ar & str;

	size_t p1(str.find_first_of('(')),p2(str.find_last_of(')'));
	std::string tag=str.substr(0,p1);
	std::string data=str.substr(p1,p2-p1);///\todo implement checks
//	object.reset(App::m_drawerList[tag].create(data));

	for(Drawer *i:App::m_drawerList)
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

//void Vertex::save(Archive &ar, const unsigned int version)const
//{
//	serializeRenderer(ar,m_renderer);
//	ar & m_point;
//}
//
//template<class Archive>
//void Vertex::load(Archive &ar, const unsigned int version)
//{
//	serializeRenderer(ar,m_renderer);
//	ar & m_point;
//}

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

//void Shape::save(Archive &ar, const unsigned int version) const
//{
//	serializeRenderer(ar,m_filler);
//	ar & ::boost::serialization::base_object<Object>( *this );
//	ar & m_children;
//	ar & m_close;
//}
//
//template<class Archive>
//void Shape::load(Archive &ar, const unsigned int version)
//{
//	serializeRenderer(ar,m_filler);
//	ar & ::boost::serialization::base_object<Object>( *this );
//	ar & m_children;
//	ar & m_close;
//}

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
