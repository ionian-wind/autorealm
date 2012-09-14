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

#ifndef MAINFRAME_H
#define MAINFRAME_H


#include <string>
#include <vector>

#include <wx/wx.h>
#include <wx/aui/aui.h>

#include <menuEngine/composite.h>
#include <menuEngine/wxmenuconverter.h>
#include <pluginEngine/plugin.h>
#include <pluginEngine/pluginprovider.h>

typedef Composite<MenuConverter> Menu;
class RenderWindow;

class ID;
class Drawer;

class MainFrame : public wxFrame
{
	Menu m_menuTree;	/// contain all menus and submenus of the menubar
	///\todo avoid the use of pointers
	typedef std::vector<RenderWindow*> MapList;
	MapList m_plans;	/// list of plans. Aka: drawing sheets
	MapList::iterator m_active;	/// iterator on the currently active plan
	wxAuiManager m_auiManager;	/// internal "window manager" of wxWidgets
	wxAuiNotebook *m_auiNotebookWorkspace;	/// contain plans'windows

	static const long ID_NOTEBOOK;

	typedef std::map<std::string, ID> AssocIDs;
	AssocIDs m_buttonIDs;	/// name of plugins are associated with an ID
	std::map<ID, Plugin*> m_plugins; /// IDs are associated with plugins \todo replace with a ptr_container
	std::vector<Drawer*> m_drawerList;///\todo replace with a ptr_list

	pluma::Pluma m_actionPlugIn;

public:
	/** \brief build the GUI and load plugins
	 *
	 * \param parent=0 wxWindow*
	 * \param id=-1 wxWindowID
	 * \param title="" std::string const&
	 *
	 */
	MainFrame(wxWindow *parent = 0, wxWindowID id = -1, std::string const &title = "");

	/** \brief default Ctor */
	~MainFrame(void);

	/** \brief change the current used plugin
	 *	This method ask to currently (if existing) used plugin to remove it's event
	 *	managers. After this, it register the new plugin to use and asks it to
	 *	do what it needs.
	 *	Plugins often need to register event managers by example.
	 *	The method give to the plugin a reference of the active RenderWindow.
	 * \param event wxCommandEvent& event to process
	 */
	void changeSelectedPlugin(wxCommandEvent &event);

protected:
private:
	/** \brief load plugins used by BUI and bind them to needed GUI elements */
	void loadRequestedPlugins(void);
};

#endif
