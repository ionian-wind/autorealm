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

#ifndef DRAWER_H
#define DRAWER_H

#include <memory>

#include "plugin.h"

class Vertex;
class wxMouseEvent;
class wxContextMenuEvent;

class Drawer : public Plugin
{
	public:
		virtual ~Drawer()=default;
		virtual void installEventManager(RenderWindow & target) throw() override;
		virtual void removeEventManager(void) throw() override;
		void leftClick(wxMouseEvent &event);
		void contextMenu(wxContextMenuEvent &event);

		virtual void draw(Vertex const &v)const=0;
		virtual std::unique_ptr<Drawer> clone(void)const=0;
	protected:
	private:
};

#endif // DRAWER_H
