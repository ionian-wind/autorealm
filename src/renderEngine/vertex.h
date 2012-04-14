/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU General Public License as published by        *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU General Public License for more details.                                *
 *                                                                                *
 *    You should have received a copy of the GNU General Public License           *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

#ifndef VERTEX_H
#define VERTEX_H

#include <memory>

#include "point.h"
#include "color.h"
#include "drawer.h"

class Vertex
{
	public:
		Vertex(void);
		Vertex(Point const &end, Color const &color,std::unique_ptr<Drawer> drawer);
		Vertex(Vertex const&other);
		void set(Point const &end, Color const &color,std::unique_ptr<Drawer> drawer);
		Vertex& operator=(Vertex const&v);
		bool operator==(Vertex const&other)const;
		void render(Color const *color=nullptr)const;
		void changeRender(std::unique_ptr<Drawer> newRender);

		Vertex clone(void)const;

		Color getColor(void)const;
		void setColor(Color const &c);
		Point getEnd(void)const;
		void setEnd(Point const &p);
	protected:
		Color m_color;
		Point m_point;
		std::unique_ptr<Drawer> m_drawer;
	private:
};

#endif // VERTEX_H
