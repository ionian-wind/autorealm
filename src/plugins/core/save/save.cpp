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

#include "save.h"

#include <fstream>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include <boost/archive/text_oarchive.hpp>

#include <renderEngine/serialization.h>

#include <gui/renderwindow.h>

Save::Save(RenderWindow *r)
:Plugin(r)
{
}

void Save::installEventManager(void) throw()
{
	wxFileDialog openFile(nullptr, _("Save text file as autorealm map"),"","","text files (*.txt)|*.txt",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if(wxID_CANCEL==openFile.ShowModal())
		return;

	std::string filename(openFile.GetPath());
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);

	Render::Group* g=static_cast<Render::Group*>(m_target);
	try
	{
		oa << (*g);
	}
	catch(std::exception &e)
	{
		wxMessageBox(e.what());
	}
}

void Save::removeEventManager(void) throw()
{
}
