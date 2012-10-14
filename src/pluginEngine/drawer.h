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

#include <gui/id.h>

#include <renderEngine/drawable.h>
#include <renderEngine/shape.h>

namespace Render
{
	class Shape;
	class Point;
}

#include "plugin.h"

class RenderWindow;
class wxMouseEvent;
class wxContextMenuEvent;
class wxCommandEvent;
class wxMenu;

class Drawer : public Plugin
{
public:
private:
	static ID m_menuIds[3];///\todo move in gui module instead of pluginEngine
	static wxMenu *m_menu; ///\todo move in gui module instead of pluginEngine
	Render::Shape m_shape;
	bool m_shape1stPoint=false;
	std::unique_ptr<Renderer> m_selectedRenderer;
	std::string m_tagList;
public:
	Drawer(RenderWindow *window, std::unique_ptr<Renderer> r, std::string const &tags);
	Drawer(Drawer const& other);
	virtual ~Drawer(void)throw();
	virtual void installEventManager(void) throw() override;
	virtual void removeEventManager(void) throw() override;

	void firstPoint(wxMouseEvent &event);
	void secondPoint(wxMouseEvent &event);
	void addPoint(wxMouseEvent &event);

	void addVertex(Render::Point const &p);

	void moveMouse(wxMouseEvent &event);
	void contextMenu(wxContextMenuEvent &event);
	void render(void);

	void finalizeShape(wxCommandEvent &event);

	operator Renderer&(void);
	bool operator==(std::string const& tag);
	std::string const getTags(void)const;
	Renderer *create(std::string const& str)const;
protected:
	void createShape(void);
};

#endif // DRAWER_H
