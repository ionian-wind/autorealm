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

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <vector>

#include <wx/glcanvas.h>

class Drawer;

#include <renderEngine/group.h>
#include <pluginEngine/renderer.h>
#include "appconfig.h"

class RenderWindow : public Render::Group, public wxGLCanvas
{
	friend class boost::serialization::access;

	wxGLContext *m_context;
	std::unique_ptr<Renderer> m_defaultRenderers[AppConfig::RENDERER::LASTRENDERER];
	double m_xo = 0, m_yo = 0; //! origin for x and y axes
	double m_xm, m_ym;//! maximum for x and y axes

public:
	/** \brief event manager for drawing requests
	 *	\param wxEvent&ev
	 */
	void onDraw(wxEvent &ev);

	/** \brief Ctor
	 *
	 * \param parent wxFrame* parent window
	 * \param args int* arguments for wxGLCanvas
	 * \param border Color const&
	 * \param filler Color const&
	 */
	RenderWindow(wxFrame *parent, int *args);

	/** Destructor */
	~RenderWindow(void) throw();

	/** \brief prepare the opengl drawing */
	void startRendering(void);
	/** \brief apply the drawing and clean OpenGL buffers */
	void finalizeRendering(void);

	Renderer const& getBorder(void)const throw();
	Renderer const& getFiller(void)const throw();

	void setBorder(Renderer const&border);
	void setFiller(Renderer const&filler);

	void checkDefaultRenderers(void) const;
private:
	/** \brief allow the object to be serialized
	 *	\note is it really interesting to restore last selected colors?
	 *	\param ar Archive&
	 *	\param version const unsignedint
	 */
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version);

};
#endif
