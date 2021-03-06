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

#include <pluginEngine/renderer.h>
#include <pluginEngine/drawerlist.h>

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

Renderer const& RenderWindow::getBorder(void)const throw()
{
	return *m_defaultRenderers[AppConfig::RENDERER::BORDER];
}

Renderer const& RenderWindow::getFiller(void)const throw()
{
	return *m_defaultRenderers[AppConfig::RENDERER::FILLER];
}

//void RenderWindow::setBorder(Renderer const&border)
//{
//	m_defaultRenderers[AppConfig::RENDERER::BORDER].reset(border.clone());
//}
//
//void RenderWindow::setFiller(Renderer const&filler)
//{
//	m_defaultRenderers[AppConfig::RENDERER::FILLER].reset(filler.clone());
//}

void RenderWindow::checkDefaultRenderers(void)const
{
	std::string except;

	for(size_t i=AppConfig::FIRSTRENDERER;i<AppConfig::LASTRENDERER;++i)
	{
		if(!m_defaultRenderers[i])
		{
			except+="Default drawer \"";
			except+=AppConfig::getRenderer(AppConfig::RENDERER::BORDER);
			except+="\" was not found.\n";
		}
	}
	if(!except.empty())
		throw std::runtime_error(std::string("Fatal error:\n"+except));
}

void RenderWindow::setDefaultRenderers(void)
{
	DrawerList const&drawers(DrawerList::GetInstance());
	for(Drawer *i:drawers.m_drawerList)
	{
		Renderer const&r(*i);
		if((*i)==AppConfig::getRenderer(AppConfig::RENDERER::BORDER))
			m_defaultRenderers[AppConfig::RENDERER::BORDER].reset(r.clone());
		if((*i)==AppConfig::getRenderer(AppConfig::RENDERER::FILLER))
			m_defaultRenderers[AppConfig::RENDERER::FILLER].reset(r.clone());
	}

	try
	{
		checkDefaultRenderers();
	}
	catch(std::runtime_error &e)
	{
		std::string tmp(e.what());
		tmp+="Plug-ins were searched in: ";
		tmp+=AppConfig::buildPath(AppConfig::INFO::PLUGINS);
		tmp+="\n";

		tmp+="\ndrawers found:\n\t";
		for(Drawer* plugin: drawers.m_drawerList)
		{
			tmp+=plugin->getTags();
			tmp+="\n\t";
		}

		throw std::runtime_error(tmp);
	}
}
