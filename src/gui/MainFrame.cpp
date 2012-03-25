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

#include <functional>

#include "RenderWindow.h"
#include "pluginEngine/container.h"

const long MainFrame::ID_NOTEBOOK = wxNewId();
const long MainFrame::ID_MENUQUIT = wxNewId();

MainFrame::~MainFrame(void)
{
	std::vector<Item*>::iterator ita;
	for(ita=m_items.begin();ita!=m_items.end();++ita)
		delete *ita;

	m_auiManager.UnInit();
}

MainFrame::MainFrame(wxWindow *parent,wxWindowID id,std::string const &title)
:wxFrame(parent,id,title)
{
    wxMenu* MenuFile;
    wxMenuItem* MenuItemExit;

    m_auiManager.SetManagedWindow(this);
    m_auiNotebookWorkspace = new wxAuiNotebook(this, ID_NOTEBOOK);

//add first page to notebook
    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
	RenderWindow *first=new RenderWindow((wxFrame*)m_auiNotebookWorkspace,args);
    m_auiNotebookWorkspace->AddPage(first, "Map 1", true);
    m_plans.push_back(first);
    m_active=m_plans.begin();

    m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Name(_T("Workspace")).Caption(_("Workspace")).CaptionVisible(false).CloseButton(false).Center());
    m_auiManager.Update();

//add menu entry File->Exit
    m_MenuBar = new wxMenuBar();
	SetMenuBar(m_MenuBar);

    MenuFile = new wxMenu();
    m_MenuBar->Append(MenuFile, _("&File"));
    MenuItemExit = new wxMenuItem(MenuFile, ID_MENUQUIT, _("&Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemExit);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::onQuit, this, ID_MENUQUIT);

//add all plug-ins entries
	m_actionPlugIn.acceptProviderType<ItemProvider>();
	m_actionPlugIn.loadFromFolder("plugin");
	m_actionPlugIn.getProviders(m_actionProviders);

	std::vector<ItemProvider*>::iterator ita;
	for(ita=m_actionProviders.begin();ita!=m_actionProviders.end();++ita)
	{
		m_items.push_back((*ita)->create());
		m_items.back()->registerIn(this,m_containers,m_appConfig);
		Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::changeLeftAction,this,m_items.back()->m_id,m_items.back()->m_id);
	}

	for(std::map<std::string,Container>::iterator it=m_containers.begin();it!=m_containers.end();++it)
		m_auiManager.AddPane(it->second.first,it->second.second);
	m_auiManager.Update();
}

void MainFrame::onQuit(wxCommandEvent& event)
{
    Close();
}

void MainFrame::changeLeftAction(wxCommandEvent& ev)
{
	static ITEM_CALLBACK s_actualCallback=0;
	static Item *s_actualItem=0;

	if(s_actualCallback)
		(*m_active)->Unbind(wxEVT_LEFT_DOWN, s_actualCallback, s_actualItem);

	std::vector<Item*>::iterator it;
	for(it=m_items.begin();it!=m_items.end();++it)
		if((*it)->m_id==ev.GetId())
		{
			s_actualItem=*it;
			s_actualCallback=s_actualItem->m_callback;
			break;
		}
	if(it==m_items.end())
		throw std::runtime_error("item not found");
	(*m_active)->Bind(wxEVT_LEFT_DOWN, s_actualCallback, s_actualItem);
}
