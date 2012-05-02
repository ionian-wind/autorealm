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

#ifndef _MAINFRAME_H
#define _MAINFRAME_H


#include <string>
#include <vector>
#include <list>
#include <memory>

#include <wx/wx.h>
#include <wx/aui/aui.h>

//#include <pluginEngine/item.h>
#include "appconfig.h"
#include <menuEngine/menu.h>
#include <pluginEngine/plugin.h>

class RenderWindow;
//class ToolbarItem;
//class ToolBar;
class ID;

class MainFrame : public wxFrame
{
public:

public:
protected:
private:
    Menu m_menuTree;
    std::vector<RenderWindow*> m_plans;
    std::vector<RenderWindow*>::iterator m_active;
    wxAuiManager m_auiManager;
    wxAuiNotebook* m_auiNotebookWorkspace;

    static const long ID_NOTEBOOK;

	std::vector<PluginProvider*> m_actionProviders;
	std::map<std::string, ID> m_buttonIDs;// name of plugins are associated with an ID
	std::map<ID,std::unique_ptr<Plugin>> m_plugins;// IDs are associated with plugins
//	std::vector<std::unique_ptr<Plugin>>::iterator m_selected;
	pluma::Pluma m_actionPlugIn;

public:
    /** \brief build the window and load plug-ins
     *
     * \param parent=0 wxWindow*
     * \param id=-1 wxWindowID
     * \param title="" std::string const&
     *
     */
    MainFrame(wxWindow *parent=0,wxWindowID id=-1,std::string const &title="");
    /** \brief Change the action taken when a the left button of the mouse is pressed on the active RenderWindow
     *
     * \param ev wxCommandEvent& event containing the item which were pushed
     */
	void changeLeftAction(wxCommandEvent& ev);
    /** \brief clean datas
     */
    ~MainFrame(void);

protected:

private:
    /** \brief Exit the application
     * \param event wxCommandEvent&
     */
    void onQuit(wxCommandEvent& event);
};

#endif

//!\todo PlumaLack#1 implement a Provider::getProvider(std::string const &plugName) in pluma to remove dumb code here
