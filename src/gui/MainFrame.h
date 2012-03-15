/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel B�renger                                               *
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

#include <wx/wx.h>
#include <wx/aui/aui.h>

#include "pluginEngine/item.h"
#include "appconfig.h"

class RenderWindow;
class ToolbarItem;
class ToolBar;

class MainFrame : public wxFrame
{
public:
	const AppConfig m_appConfig;
protected:
private:
//    std::vector<RenderWindow*> m_plans;
//    std::vector<RenderWindow*>::iterator m_active;
    wxAuiManager m_auiManager;
    wxAuiNotebook* m_auiNotebookWorkspace;
    wxMenuBar* m_MenuBar;

    static const long ID_NOTEBOOK;
    static const long ID_MENUQUIT;

	std::vector<ItemProvider * > m_actionProviders;
	std::vector<Item* > m_items;
    std::vector<Item* >::iterator m_selected;
	pluma::Pluma m_actionPlugIn;
	std::map<std::string,Container > m_containers;

public:
    MainFrame(wxWindow *parent=0,wxWindowID id=-1,std::string const &title="");
    ~MainFrame(void);
protected:
private:
    void onQuit(wxCommandEvent& event);
};
#endif
