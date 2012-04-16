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

#include "menudata.h"

#include <wx/menu.h>

MenuData::MenuData(std::string const &nAME, std::string const& hELP, wxItemKind const kIND)
:kind(kIND),help(hELP),name(nAME)
{
	m_corruptedFile=("configuration file corrupted\n");
	checkName();
}

MenuData::MenuData(void)
:kind(wxITEM_NORMAL),help(""),name()
{
	m_corruptedFile=("configuration file corrupted\n");
}

void MenuData::readFromFile(std::unique_ptr<TextFile> &source)
{
	try
	{
		name=source->readLine();
		help=source->readLine();
		std::string tmp(source->readLine());
		sscanf(tmp.c_str(),"%d",(int*)(&kind));
	}
	catch(std::runtime_error &e)
	{
		std::string err(m_corruptedFile);
		err+=e.what();
		throw std::runtime_error(err);
	}
	checkName();
}

void MenuData::checkName(void)
{
	if(name.empty())
		throw std::runtime_error("item without name are not allowed");
}

long MenuData::findIn(wxMenu *parent)const
{
	return parent->FindItem(name);
}

long MenuData::findIn(wxMenuBar *parent)const
{
	return parent->FindMenu(name);
}

bool MenuData::exist(wxMenu *parent)const
{
	return NOT_FOUND!=parent->FindItem(name);
}

wxMenuItem*MenuData::addTo(wxMenu *parent,long id)const
{
	return parent->Append(new wxMenuItem(parent,id,name,help,kind));
}

wxMenu* MenuData::addTo(wxMenu *parent)const
{
	wxMenu *submenu=new wxMenu();
	parent->AppendSubMenu(submenu,name);
	return submenu;
}

wxMenu* MenuData::addTo(wxMenuBar *parent)const
{
	wxMenu *submenu=new wxMenu();
	parent->Append(submenu,name);
	return submenu;
}
