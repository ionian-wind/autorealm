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

#include <gui/id.h>

namespace Render
{
	class Vertex;
	class Shape;
}

#include "plugin.h"

class RenderWindow;
class wxMouseEvent;
class wxContextMenuEvent;
class wxCommandEvent;
class wxMenu;

class Drawer : public Plugin
{
	ID m_menuIds[3];
	wxMenu *m_menu=nullptr;
	Render::Shape *m_shape;
public:
	Drawer(void);
	virtual ~Drawer(void)throw();
	virtual void installEventManager(RenderWindow &target) throw() override;
	virtual void removeEventManager(void) throw() override;

	void firstPoint(wxMouseEvent &event);

	void leftClick(wxMouseEvent &event);
	void moveMouse(wxMouseEvent &event);
	void contextMenu(wxContextMenuEvent &event);
	void render(void);

	void finalizeShape(wxCommandEvent &event);

	virtual void draw(Render::Vertex const &v)const = 0;
	virtual std::unique_ptr<Drawer> clone(void)const = 0;
protected:
	void closer(wxCommandEvent &event);
	void adder(wxCommandEvent &event);
	void shifter(wxCommandEvent &event);
	void createShape(void);
};

#endif // DRAWER_H
