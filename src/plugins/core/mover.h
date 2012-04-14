#ifndef MOVER_H
#define MOVER_H

#include <pluginEngine/mutator.h>
#include <renderEngine/point.h>

class Vertex;

class Mover : public Mutator
{
	public:
		void visit(Group& v);
		void visit(Shape& v);
		Point m_distance;
	protected:
	private:
		Vertex mover(Vertex const&v);
};

#endif // MOVER_H
