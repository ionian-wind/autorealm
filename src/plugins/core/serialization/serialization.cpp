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

#include "serialization.h"

#include <fstream>
#include <wx/filedlg.h>
#include <boost/archive/text_iarchive.hpp>

#include <gui/renderwindow.h>
#include <renderEngine/shape.h>
#include <renderEngine/group.h>

Serialization::Serialization(RenderWindow *r)
:Plugin(r)
{
}

void Serialization::installEventManager(void) throw()
{
	wxFileDialog openFile(nullptr, _("Open text file as autorealm map"),"","","text files (*.txt)|*.txt",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if(wxID_CANCEL==openFile.ShowModal())
		return;

	std::string filename(openFile.GetPath());
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);
//Following code should be ok, but boost::serialization seem to be unable to manipulate std::unique_ptr
	ia.register_type(static_cast<Render::Group*>(nullptr));
	ia.register_type(static_cast<Render::Shape*>(nullptr));
//	boost::serialization::void_cast_register(static_cast<Render::Group*>(nullptr),static_cast<Render::Object*>(nullptr));
//	boost::serialization::void_cast_register(static_cast<Render::Shape*>(nullptr),static_cast<Render::Object*>(nullptr));
//	ia >> static_cast<Render::Group&>(target);


//    // create and open a character archive for output
//    std::ofstream ofs(filename);
//
//    // create class instance
//    const master g(35);
//
//    // save data to archive
//    {
//        boost::archive::text_oarchive oa(ofs);
//        // write class instance to archive
//        oa << g;
//    	// archive and stream closed when destructors are called
//    }
//
//    // ... some time later restore the class instance to its orginal state
//    master newg;
//    {
//        // create and open an archive for input
//        std::ifstream ifs(filename);
//        boost::archive::text_iarchive ia(ifs);
//        // read class state from archive
//        ia >> newg;
//        // archive and stream closed when destructors are called
//    }
//
//
//	createShape();
//	m_target->Bind(wxEVT_LEFT_DOWN, &Drawer::leftClick, this);
//	m_target->Bind(wxEVT_CONTEXT_MENU, &Drawer::contextMenu, this);
//
//	m_target->Bind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::createOpenedFigure, this, Menu_Popup_OpenFig, Menu_Popup_OpenFig);
//	m_target->Bind(wxEVT_COMMAND_MENU_SELECTED, &Drawer::createClosedFigure, this, Menu_Popup_CloseFig, Menu_Popup_CloseFig);
}

void Serialization::removeEventManager(void) throw()
{
}
