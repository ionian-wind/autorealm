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

#include "plugins/interface/container.h"

const long MainFrame::ID_NOTEBOOK = wxNewId();
const long MainFrame::ID_MENUQUIT = wxNewId();

MainFrame::~MainFrame(void)
{
	m_auiManager.UnInit();
}

MainFrame::MainFrame(wxWindow *parent,wxWindowID id,std::string const &title)
//:wxFrame(parent,id,title)
{
    wxMenu* MenuFile;
    wxMenuItem* MenuItemExit;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    m_auiManager.SetManagedWindow(this);
    m_auiNotebookWorkspace = new wxAuiNotebook(this, ID_NOTEBOOK);

//add first page to notebook
    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
//    RenderWindow *tmp= new RenderWindow((wxFrame*)m_auiNotebookWorkspace,args);
//    tmp->setName("Map 1");
//    m_plans.push_back(tmp);
//    m_active=m_plans.begin();
    m_auiNotebookWorkspace->AddPage(new RenderWindow((wxFrame*)m_auiNotebookWorkspace,args), "Map 1", true);

    m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Name(_T("Workspace")).Caption(_("Workspace")).CaptionVisible(false).CloseButton(false).Center());
    m_auiManager.Update();

//add menu entry File->Exit
    m_MenuBar = new wxMenuBar();
    MenuFile = new wxMenu();
    MenuItemExit = new wxMenuItem(MenuFile, ID_MENUQUIT, _("&Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemExit);
    m_MenuBar->Append(MenuFile, _("&File"));

	SetMenuBar(m_MenuBar);

	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::onQuit, this, ID_MENUQUIT);


	m_actionPlugIn.acceptProviderType<ItemProvider>();
	m_actionPlugIn.loadFromFolder("plugin");
	m_actionPlugIn.getProviders(m_actionProviders);

	std::vector<ItemProvider*>::iterator ita;
	for(ita=m_actionProviders.begin();ita!=m_actionProviders.end();++ita)
	{
		m_items.push_back((*ita)->create());
		(*m_items.rbegin())->registerIn(this,m_containers,m_appConfig);
	}
	for(std::map<std::string,Container>::iterator it=m_containers.begin();it!=m_containers.end();++it)
		it->second.first->Realize();
	m_auiManager.Update();
}

void MainFrame::onQuit(wxCommandEvent& event)
{
    Close();
}
