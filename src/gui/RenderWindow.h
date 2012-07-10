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
public:
    /** \brief initialize the sheet to be able to recept drawing and call Group::draw */
    virtual void draw();
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
    /** \brief select the last object in the vector of ojects contained
     *
     * \return void selectLastObject(void)
     *
     */
    void selectLastObject(void) throw();
    /** \brief add a vertex to the selected shape.
     *
     * \param x wxCoord
     * \param y wxCoord
     * \param drawer std::unique_ptr<Drawer>
     * \pre m_selection is a pointer on a Shape object
     * \throw bad_cast if the selected object is not a shape
     */
    void addVertex(wxCoord x, wxCoord y,std::unique_ptr<Drawer> drawer);

private:
    Object *m_selection;
    wxGLContext * m_context;
    Color m_selectedColor;
};
#endif
