#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <pluginEngine/renderer.h>

#include "group.h"
#include "shape.h"
#include "vertex.h"
#include "color.h"

BOOST_CLASS_EXPORT(Render::Group);
BOOST_CLASS_EXPORT(Render::Shape);
BOOST_CLASS_EXPORT(Render::Object);

#define SERIALIZATION_WITHOUT_RENDERER

#ifndef SERIALIZATION_WITHOUT_RENDERER
//////////////////////////////////////
//              Renderer            //
//////////////////////////////////////
template<typename Archive>
void Renderer::serialize(Archive & ar, const unsigned int version)
{
	Render::Drawable *tmp=m_drawable. get();
	ar & tmp;
	m_drawable.reset(tmp);
}
#endif

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
void Vertex::save(Archive &ar, const unsigned int version)const
{
#ifndef SERIALIZATION_WITHOUT_RENDERER
	Renderer *tmp=m_renderer.get();
	ar & tmp;
#endif
	ar & m_point;
}

template<class Archive>
void Vertex::load(Archive &ar, const unsigned int version)
{
#ifndef SERIALIZATION_WITHOUT_RENDERER
	Renderer *tmp;
	ar & tmp;
	m_renderer.reset(tmp);
#endif
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
void Shape::save(Archive &ar, const unsigned int version) const
{
#ifndef SERIALIZATION_WITHOUT_RENDERER
	Renderer *tmp=m_renderer.get();
	ar & tmp;
#endif
	ar & ::boost::serialization::base_object<Object>( *this );
	ar & m_children;
	ar & m_close;
}

template<class Archive>
void Shape::load(Archive &ar, const unsigned int version)
{
#ifndef SERIALIZATION_WITHOUT_RENDERER
	Renderer *tmp;
	ar & tmp;
	m_renderer.reset(tmp);
#endif
	ar & ::boost::serialization::base_object<Object>( *this );
	ar & m_children;
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
