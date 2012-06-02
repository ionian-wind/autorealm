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

class MoverProvider: public PluginProvider{
public:
    Plugin * create() const{ return new Mover(); }
	const std::string getPluginName(void)const{return "Mover";}
};

#endif // MOVER_H
