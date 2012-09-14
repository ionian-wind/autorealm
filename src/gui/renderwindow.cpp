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


#include "renderwindow.h"
#include <wx/frame.h>
#include <GL/glu.h>
#include <wx/dcclient.h>

#include <renderEngine/point.h>
#include <renderEngine/vertex.h>
#include <renderEngine/shape.h>

#include <pluginEngine/drawer.h>
#include "appconfig.h"

void RenderWindow::onDraw(wxEvent &ev)
{
	startRendering();
	draw();
	finalizeRendering();
}

RenderWindow::RenderWindow(wxFrame *parent, int *args)
: wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
	m_context = new wxGLContext(this);
	// To avoid flashing on MSW
	SetBackgroundStyle(wxBG_STYLE_CUSTOM);
	Bind(wxEVT_PAINT, &RenderWindow::onDraw, this);
}

RenderWindow::~RenderWindow(void) throw()
{
	delete m_context;
}

void RenderWindow::startRendering(void)
{
	int w, h;
	GetSize(&w, &h);

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
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	m_xm = w;
	m_ym = h;
	gluOrtho2D(m_xo, m_xm, m_ym, m_yo);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void RenderWindow::finalizeRendering(void)
{
	glFlush();
	SwapBuffers();
}

void RenderWindow::checkDefaultRenderers(void)const
{
	std::string except;
	if(!m_border)
		except+="Default border was not found.\n";
	if(!m_filler)
		except+="Default filler was not found.\n";
	if(!except.empty())
		throw std::runtime_error(std::string("Fatal error:\n"+except));
}
