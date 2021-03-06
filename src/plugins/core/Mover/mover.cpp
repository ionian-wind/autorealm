/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU Lesser General Public License as published by *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU Lesser General Public License for more details.                         *
 *                                                                                *
 *    You should have received a copy of the GNU Lesser General Public License    *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

#include "mover.h"

#include <algorithm>

#include <renderEngine/group.h>
#include <renderEngine/shape.h>
#include <renderEngine/vertex.h>

void Mover::visit(Render::Group &v)
{
}

void Mover::visit(Render::Shape &v)
{
//	std::transform(
//		v.getFirstChild(),
//		v.getLastChild(),
//		v.getFirstChild(),
//		std::bind(std::mem_fun(&Mover::mover), this, std::placeholders::_1)
//	);
}

//Render::Vertex Mover::mover(Render::Drawable const &v)
//{
//	Render::Vertex v1(v);
//	v1.setEnd(v1.getEnd() + m_distance);
//	return v1;
//}
