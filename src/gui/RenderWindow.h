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


#include "../render/Object.h"
#include <wx/glcanvas.h>
#include <vector>
#include <string>

class RenderWindow : public Object, public wxGLCanvas
{
  public:
    virtual void draw();
    RenderWindow(wxFrame* parent, int* args);
    RenderWindow & operator=(const RenderWindow & source);
    void setName(std::string const &str)
    {
    	m_winName=str;
    }
    std::string getName(void)const
    {
    	return m_winName;
    }
//    RenderWindow(const RenderWindow & source);

  private:
  	std::string m_winName;
	std::vector<Object> m_graphics;
	Object * m_selection;
	wxGLContext * m_context;

};
#endif
