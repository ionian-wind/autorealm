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
#include <Pluma/Pluma.hpp>

#include "menuitemconfig.h"
#include "toolbaritemconfig.h"

class Drawer;
class ID;
class Plugin;

class RenderWindow;

class MainFrame : public wxFrame
{
	typedef std::map<std::string, ID> AssocIDs;
	AssocIDs m_buttonIDs;	/// name of plugins are associated with an ID
	pluma::Pluma m_actionPlugIn;
	std::map<ID, Plugin*> m_plugins; /// IDs are associated with plugins \todo replace with a ptr_container
	///\todo avoid the use of pointers
	typedef std::vector<RenderWindow*> MapList;
	MapList m_plans;	/// list of plans. Aka: drawing sheets
	MapList::iterator m_active;	/// iterator on the currently active plan
	wxAuiManager m_auiManager;	/// internal "window manager" of wxWidgets
	wxAuiNotebook *m_auiNotebookWorkspace;	/// contain plans'windows

	void loadRequestedPlugins(Node<MenuItemConfig> &tree);
	void changeSelectedPlugin(wxCommandEvent &event);

	void buildToolbars(wxAuiManager &mgr,Node<ToolbarItemConfig> & origin);
	wxAuiToolBar* buildPaneComponents(Node<ToolbarItemConfig> &data);

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

	RenderWindow* getActive(void)const;
};

#endif
