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

#include "mainframe.h"

#include "renderwindow.h"

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, std::string const &title)
: wxFrame(parent, id, title)
{
	m_auiManager.SetManagedWindow(this);
	m_auiNotebookWorkspace = new wxAuiNotebook(this);
	int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};
	RenderWindow *first = new RenderWindow((wxFrame *)m_auiNotebookWorkspace, args );
	m_auiNotebookWorkspace->AddPage(first, "Map 1", true);
	m_plans.push_back(first);
	m_active = m_plans.begin();
	m_auiManager.AddPane(m_auiNotebookWorkspace, wxAuiPaneInfo().Center());
	m_auiManager.Update();
}

MainFrame::~MainFrame(void)
{
	m_auiManager.UnInit();
}

RenderWindow* MainFrame::getActive(void)const
{
	return *m_active;
}
