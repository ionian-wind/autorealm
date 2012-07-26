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

#ifndef _RENDERWINDOW_H
#define _RENDERWINDOW_H

#include <vector>

#include <wx/glcanvas.h>

#include <renderEngine/group.h>
#include <renderEngine/color.h>

class RenderWindow : public Group,public wxGLCanvas
{
    friend class boost::serialization::access;
public:
	/** \brief event manager for drawing requests
     * \param wxEvent&ev
     */
    void onDraw(wxEvent&ev);
    /** \brief Constructor
     *
     * \param parent wxFrame*
     * \param args int*
     *
     */
    RenderWindow(wxFrame* parent, int* args);
    /** Destructor */
    ~RenderWindow(void) throw();

	void startRendering(void);
    void finalizeRendering(void);

	Color getBorderColor(void)const throw(){return m_borderColor;}
	Color getFillerColor(void)const throw(){return m_fillerColor;}
private:
	template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & m_context;
        ar & m_borderColor;
        ar & m_fillerColor;
    }

private:
    wxGLContext * m_context;
    Color m_borderColor;
    Color m_fillerColor;
};
#endif
