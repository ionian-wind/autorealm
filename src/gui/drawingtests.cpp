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

#include "drawingtests.h"
#include <renderEngine/shape.h>
#include <renderEngine/point.h>
#include <renderEngine/color.h>
#include <renderEngine/vertex.h>
#include <renderEngine/linemonocolor.h>

DrawingTests::DrawingTests()
{
}

std::unique_ptr<Shape> DrawingTests::create(void)
{
	std::unique_ptr<Shape> s(new Shape());

	s->setFiller(Color(0,0,0,1));
	Point p(100,85,0);

	Vertex l0;l0.set(p,
					Color(1,0,0,1),LineMonoColor().clone());
	Vertex l1;l1.set(Point(10,70,0),
					Color(0,1,0,1),LineMonoColor().clone());
	Vertex l2;l2.set(Point(50,100,0),
					Color(0,0,1,1),LineMonoColor().clone());
	Vertex l3;l3.set(p,
					Color(0.5,0.5,0,1),LineMonoColor().clone());

	s->push_back(l0);
	s->push_back(l1);
	s->push_back(l2);
	s->push_back(l3);
	return s;
}

Mover DrawingTests::move(void)
{
	Mover m;
	m.m_distance=Point(00,00,00);
	return m;
}
