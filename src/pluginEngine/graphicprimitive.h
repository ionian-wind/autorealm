#ifndef GRAPHICPRIMITIVE_H
#define GRAPHICPRIMITIVE_H

#include <renderEngine/vertex.h>
#include "drawer.h"


class GraphicPrimitive : public Drawer, public Render::Vertex
{
	public:
		GraphicPrimitive(void)=default;//!\todo remove this ctor needed because of Pluma's macros
		GraphicPrimitive(GraphicPrimitive const& other);
		GraphicPrimitive(Render::Point const &point,GraphicPrimitive const& primitive);
	protected:
	private:
};

#endif // GRAPHICPRIMITIVE_H
