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


#include "Line.h"
#include <GL/gl.h>

void Line::lineDraw(const Point3D & endLine,bool ignoreColor) const
{
    glColor4d(m_color.m_red,m_color.m_green,m_color.m_blue,m_color.m_alpha);
    //TODO(berenger#1#) merge Point3D with Point. We need 3D at least to manage planes (send to fore/back_ground by example)
    glVertex3d(m_x,m_y,m_z);
    glVertex3d(endLine.m_x,endLine.m_y,endLine.m_z);
}
