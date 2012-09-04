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

#include "splash.h"

#include <wx/sizer.h>
#include <wx/statbmp.h>

#include "appconfig.h"
#include "id.h"

#include <utils/utils.h>

#include <boost/filesystem.hpp>

Splash::Splash()
	: wxFrame(nullptr, -1, "")
{
	if(exists(boost::filesystem::path(AppConfig::buildPath(AppConfig::GRP_RES) + "splash/splash.png")))
	{
		wxBoxSizer *BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
		m_splash = new wxStaticBitmap(this, ID(), loadImage("splash/splash.png"));///\todo move this string into a configuration file
		BoxSizer1->Add(m_splash);
		SetSizer(BoxSizer1);
		BoxSizer1->Fit(this);
		Show();
	}
	else
		throw std::runtime_error("unable to find splash screen image which should be located at "+AppConfig::buildPath(AppConfig::GRP_RES) + "splash/splash.png");
}
