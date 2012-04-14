#ifndef DRAWER_H
#define DRAWER_H

#include <memory>

#include "plugin.h"

class Vertex;

class Drawer : public Plugin
{
	public:
		virtual ~Drawer(){};
		virtual void draw(Vertex const &v)const=0;
		virtual std::unique_ptr<Drawer> clone(void)const=0;
	protected:
	private:
};

#endif // DRAWER_H
