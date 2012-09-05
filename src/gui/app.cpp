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

#include <exception>

#include <wx/splash.h>

#include "app.h"
#include "mainframe.h"

IMPLEMENT_APP(App)

bool App::OnInit()
{
	bool wxsOK = true;

	try
	{
		wxInitAllImageHandlers();

		if(wxsOK)
		{
			wxImage image;
			image.LoadFile(AppConfig::buildPath(AppConfig::GRP_RES) + "splash/splash.png");

			wxSplashScreen* splash = new wxSplashScreen(image, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_NO_TIMEOUT, 0,NULL,wxID_ANY);
			wxAppConsole::Yield(true);
			m_app = new MainFrame(0);

#ifdef TEST_SPLASH
			time_t start, end;
			time(&start);
			time(&end);
			while(difftime(end,start)<10.0)
				time(&end);
#endif
			delete splash;
			m_app->Show();
			SetTopWindow(m_app);
		}
	}
	catch(std::exception &e)
	{
		wxsOK = true;
		wxMessageBox(e.what(), "Fatal exception");
	}

	return wxsOK;
}

App::App(void) = default;
