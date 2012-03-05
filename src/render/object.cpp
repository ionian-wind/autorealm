#include "object.h"

Object::Object(void)
:m_owner(NULL)
{
}

Object::Object(Group *owner)
:m_owner(owner)
{
}

void Object::move(const Point<> & distance)
{
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(std::bind1st(Object::move,distance)));
	for(Children::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->move(distance);
}

void Object::rotate(short degree)
{
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(std::bind1st(Object::rotate,degree)));
	for(Children::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->rotate(degree);
}

void Object::rotate(float radian)
{
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(std::bind1st(Object::rotate,radian)));
	for(Children::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->rotate(radian);
}

void Object::resize(unsigned char widthPercent, unsigned char heightPercent)
{
	for(typename Children::iterator it=m_children.begin();it!=m_children.end();++it)
		(*it)->resize(widthPercent,heightPercent);
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(
//				std::bind1st(
//					std::bind1st(resize,
//									widthPercent),
//								heightPercent))
//			);
}
