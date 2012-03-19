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

#ifndef _RENDERWINDOW_H
#define _RENDERWINDOW_H

#include <vector>
#include <string>

#include <wx/glcanvas.h>

#include "renderEngine/Group.h"

class RenderWindow : public Group,public wxGLCanvas
{
public:
    virtual void draw();
    void onDraw(wxEvent&ev);
    RenderWindow(wxFrame* parent, int* args);
    ~RenderWindow(void);
    void setName(std::string const &str);
    std::string getName(void)const;
    int getWidth(void)const;
    int getHeight(void)const;
    Object *getSelection(void);
//    void appendPoint(Point const & coordinates);
//    void newShape(Shape const & shape);

private:
    std::string m_name;
    Object *m_selection;
    wxGLContext * m_context;
};
#endif
