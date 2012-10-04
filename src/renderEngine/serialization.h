#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "group.h"
#include "shape.h"
#include "vertex.h"
#include "color.h"

//template<typename Archive>
//void Renderer::serialize(Archive & ar, const unsigned int version)
//{
//	Render::Drawable *tmp=m_drawable. get();
//	ar & tmp;
//	m_drawable.reset(tmp);
//}

namespace Render
{

template<class Archive>
void Vertex::save(Archive &ar, const unsigned int version)const
{
	Renderer *tmp=m_renderer.get();
	ar & m_point;
	ar & tmp;
}

template<class Archive>
void Vertex::load(Archive &ar, const unsigned int version)
{
	Renderer *tmp;
	ar & m_point;
	ar & tmp;
	m_renderer.reset(tmp);
}

template<class Archive>
void Group::serialize(Archive &ar, const unsigned int version)
{
	ar & boost::serialization::base_object<Render::Object>( *this );
	ar.register_type(static_cast<Render::Group*>(nullptr));
	ar.register_type(static_cast<Render::Shape*>(nullptr));
	ar &m_children;
}

template<class Archive>
void Shape::save(Archive &ar, const unsigned int version) const
{
	Renderer *tmp=m_filler.get();
	ar & ::boost::serialization::base_object<Object>( *this );
	ar & m_children;
	ar & tmp;
	ar & m_close;
}

template<class Archive>
void Shape::load(Archive &ar, const unsigned int version)
{
	Renderer *tmp;
	ar & ::boost::serialization::base_object<Object>( *this );
	ar & m_children;
	ar & tmp;
	ar & m_close;
	m_filler.reset(tmp);
}

template<class Archive>
void Point::serialize(Archive &ar, const unsigned int version)
{
	ar &m_x;
	ar &m_y;
	ar &m_z;
}

template<class Archive>
void Color::serialize(Archive &ar, const unsigned int version)
{
	ar &m_red;
	ar &m_green;
	ar &m_blue;
	ar &m_alpha;
}
}

#endif
