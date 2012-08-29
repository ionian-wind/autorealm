#include "graphicprimitive.h"

GraphicPrimitive::GraphicPrimitive(GraphicPrimitive const& other)
:Drawer(other),Render::Vertex(other)
{
}
