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


#include <map>
#include <string>
#include <vector>
#include <list>
//#include <wx/frame.h>
#include <wx/aui/aui.h>


class RenderWindow;
class ToolbarItem;
class ToolBar;

class MainFrame : public wxFrame
{
  private:
	RenderWindow * m_active;
	std::map<std::string,RenderWindow> m_plans;
	std::vector<ToolbarItem> m_toolList;
	ToolbarItem * m_selected;
	std::list<ToolBar> m_toolbars;

	wxAuiManager* m_AuiManager;
	wxAuiNotebook* m_AuiNotebookWorkspace;

	static const long ID_AUINOTEBOOKWORKSPACE;

  public:
    MainFrame(wxWindow *parent=0,wxWindowID id=-1);
  protected:
  private:
	void OnQuit(wxCommandEvent& event);
};
#endif
