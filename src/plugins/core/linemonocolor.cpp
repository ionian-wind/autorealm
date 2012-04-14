#include "linemonocolor.h"

#include <renderEngine/vertex.h>

LineMonoColor::LineMonoColor()
{
	//ctor
}

void LineMonoColor::draw(Vertex const &v)const
{
	v.getEnd().createVertice();
	v.getColor().apply();
	v.getEnd().createVertice();
}

std::unique_ptr<Drawer> LineMonoColor::clone(void)const
{
	return std::unique_ptr<LineMonoColor>(new LineMonoColor());
}
