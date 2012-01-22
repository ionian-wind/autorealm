/***************************************************************
 * Name:      autorealm_GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:     Morel Berenger
 * Created:   2011-12-15
 * Copyright:  GPL
 * License:
 * autorealm - A software to create maps
 * Copyright (C) 2011 Morel Berenger
 *
 *This file is part of autorealm.
 *
 *	autorealm is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	autorealm is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with autorealm.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************/

#include "autorealm_GUIApp.h"

//(*AppHeaders
#include "autorealm_GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(autorealm_GUIApp);

bool autorealm_GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    autorealm_GUIFrame* Frame = new autorealm_GUIFrame(0);
    Frame->Show();
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
