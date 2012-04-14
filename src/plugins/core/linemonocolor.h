#ifndef VertexMONOCOLOR_H
#define VertexMONOCOLOR_H

#include <pluginEngine/drawer.h>

class LineMonoColor : public Drawer
{
	public:
		LineMonoColor();
		virtual void draw(Vertex const &v)const;
		virtual std::unique_ptr<Drawer> clone(void)const;
	protected:
	private:
};

#endif
