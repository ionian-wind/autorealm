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


#include "MainFrame.h"
#include "RenderWindow.h"
#include "ToolbarItem.h"
#include "ToolBar.h"

const long MainFrame::ID_AUINOTEBOOKWORKSPACE = wxNewId();

MainFrame::MainFrame(wxWindow *parent,wxWindowID id)
{
    //(*Initialize(autorealm_GUIFrame)
    wxMenuBar* MenuBar;
    wxMenu* MenuFile;
    wxMenuItem* MenuItemExit;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1268,379));
    m_AuiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    m_AuiNotebookWorkspace = new wxAuiNotebook(this, ID_AUINOTEBOOKWORKSPACE, wxPoint(446,171), wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
    m_AuiManager->AddPane(m_AuiNotebookWorkspace, wxAuiPaneInfo().Name(_T("Workspace")).Caption(_("Workspace")).CaptionVisible(false).CloseButton(false).Center());
    m_AuiManager->Update();
//    MenuBar = new wxMenuBar();
//    MenuFile = new wxMenu();
//    MenuItemExit = new wxMenuItem(MenuFile, idMenuQuit, _("&Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
//    MenuFile->Append(MenuItemExit);
//    MenuBar->Append(MenuFile, _("&File"));
//    SetMenuBar(MenuBar);

//    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&autorealm_GUIFrame::OnQuit);
    //*)
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}
