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


#include "RenderWindow.h"
#include <wx/frame.h>
#include <GL/glu.h>
#include <wx/dcclient.h>

void RenderWindow::draw()//const
{
    if(!IsShown())
        return;

    SetCurrent(*m_context);
    wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White Background

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glEnable(GL_TEXTURE_2D);   // textures
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, getWidth(), getHeight());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, getWidth(), getHeight(), 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for(std::vector<Object>::iterator it=m_graphics.begin(); it!=m_graphics.end(); it++)
        it->draw();

    glFlush();
    SwapBuffers();
}

void RenderWindow::setName(std::string const &str)
{
    m_name=str;
}

std::string RenderWindow::getName(void)const
{
    return m_name;
}

int RenderWindow::getWidth(void)const
{
    return GetSize().x;
}

int RenderWindow::getHeight(void)const
{
    return GetSize().y;
}

RenderWindow::RenderWindow(wxFrame* parent, int* args)
    :wxGLCanvas(parent,wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
}
