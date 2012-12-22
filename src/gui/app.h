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

#ifndef APP_H
#define APP_H

#include <memory>
#include <map>

#include <wx/app.h>
#include <Pluma/Pluma.hpp>

#include "menuitemconfig.h"
class MainFrame;
class Drawer;
class ID;
class Plugin;

class App : public wxApp
{
	pluma::Pluma m_actionPlugIn;
	std::map<ID, Plugin*> m_plugins; /// IDs are associated with plugins \todo replace with a ptr_container
private:
	MainFrame *m_app;
private:
	/** \brief load plugins used by BUI and bind them to needed GUI elements */
	void loadRequestedPlugins(_Folder & tree);
public:
	virtual bool OnInit();
	App(void);
	/** \brief change the current used plugin
	 *	This method ask to currently (if existing) used plugin to remove it's event
	 *	managers. After this, it register the new plugin to use and asks it to
	 *	do what it needs.
	 *	Plugins often need to register event managers by example.
	 *	The method give to the plugin a reference of the active RenderWindow.
	 * \param event wxCommandEvent& event to process
	 */
	void changeSelectedPlugin(wxCommandEvent &event);
	void setDefaultRenderers(void);
};
#endif
