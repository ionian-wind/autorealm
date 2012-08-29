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

#ifndef MOVER_H
#define MOVER_H

#include <pluginEngine/mutator.h>
#include <renderEngine/point.h>

namespace Render
{
	class Drawable;
}

class Mover : public Mutator
{
public:
	void visit(Render::Group &v) override;
	void visit(Render::Shape &v) override;
protected:
private:
//	Render::Drawable& mover(Render::Drawable const &v);
};

PLUMA_INHERIT_PROVIDER(Mover, Plugin);

#endif // MOVER_H
