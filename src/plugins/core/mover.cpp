#include "mover.h"

#include <algorithm>

#include <renderEngine/group.h>
#include <renderEngine/shape.h>
#include <renderEngine/vertex.h>

void Mover::visit(Group& v)
{
}

void Mover::visit(Shape& v)
{
	std::transform(
					v.getFirstChild(),
					v.getLastChild(),
					v.getFirstChild(),
					std::bind(std::mem_fun(&Mover::mover),this,std::placeholders::_1)
					);
}

Vertex Mover::mover(Vertex const&v)
{
	Vertex v1(v);
	v1.setEnd(v1.getEnd()+m_distance);
	return v1;
}
