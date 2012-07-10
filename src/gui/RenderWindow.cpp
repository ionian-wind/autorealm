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


#include "RenderWindow.h"
#include <wx/frame.h>
#include <GL/glu.h>
#include <wx/dcclient.h>

#include <renderEngine/point.h>
#include <renderEngine/vertex.h>
#include <renderEngine/shape.h>

RenderWindow::RenderWindow(wxFrame* parent, int* args)
    :wxGLCanvas(parent,wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
    ,m_selectedColor(0,0,0,1)
{
	m_context = new wxGLContext(this);
    // To avoid flashing on MSW
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);

	Bind(wxEVT_PAINT, &RenderWindow::onDraw, this);
}

void RenderWindow::onDraw(wxEvent&ev)
{
	draw();
}

RenderWindow::~RenderWindow(void) throw()
{
	delete m_context;
}

void RenderWindow::draw()//const
{
	int w,h;
	GetSize(&w,&h);

    if(!IsShown())
        return;

    SetCurrent(*m_context);
	wxClientDC(this);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White Background

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);   // textures
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	Group::draw();

    glFlush();
    SwapBuffers();
}

void RenderWindow::selectLastObject(void) throw()
{
	m_selection=Group::m_children.back().get();
}

void RenderWindow::addVertex(wxCoord x, wxCoord y, std::unique_ptr<Drawer> drawer)
{
	dynamic_cast<Shape*>(m_selection)->push_back(
			Vertex(
					Point(x,y,0),
					m_selectedColor,
					std::move(drawer))
			);
	this->draw();
}
