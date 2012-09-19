#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <renderEngine/group.h>

namespace boost
{
namespace serialization
{
	template <class Archive>
	void serialize(Archive & ar, Render::Group & g, const unsigned int version)
	{
	}

//	template <class Archive>
//	void serialize(Archive & ar, truc & g, const unsigned int version)
//	{
//	}
//
}
}
#endif // SERIALIZER_H
