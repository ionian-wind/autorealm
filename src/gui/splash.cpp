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

#include "splash.h"

#include <wx/sizer.h>

#include "appconfig.h"
#include <utils/utils.h>

Splash::Splash()
:wxFrame(nullptr,-1,"")
{
	std::string filename(AppConfig::buildPath(AppConfig::INFO::GRP_RES)+"splash/splash.png");
	if(exists(boost::filesystem::path(filename)))
	{
		wxBoxSizer* BoxSizer1=new wxBoxSizer(wxHORIZONTAL);
		m_splash = new wxStaticBitmap(this, wxNewId(), loadImage("splash/splash.png"));
		BoxSizer1->Add(m_splash);
		SetSizer(BoxSizer1);
		BoxSizer1->Fit(this);
		Show();
	}
}

Splash::~Splash()
{
	//dtor
}