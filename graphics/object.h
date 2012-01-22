#ifndef OBJECT_H
#define OBJECT_H

#include "d3point.h"

class Object
{
	public:
		Object();
		virtual ~Object();
	protected:
		D3Point m_origin;
	private:
};

#endif // OBJECT_H
