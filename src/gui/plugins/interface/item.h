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
#ifndef ITEM_H
#define ITEM_H

#include <set>
#include <string>

#include <Pluma/Pluma.hpp>

#include <wx/dataobj.h>
#include <wx/bitmap.h>
#include <wx/defs.h>
#include <wx/frame.h>

class wxAuiManager;
class wxMenuItem;
class Container;
class AppConfig;

struct MenuData
{
	MenuData(std::string const &nAME, std::string const& hELP, wxItemKind const kIND)
	:kind(kIND),help(hELP),name(nAME){}

	MenuData(void)
	:kind(),help(),name(){}

	wxItemKind kind;
	std::string help;
	std::string name;
};

class Item
{
public:
protected:
//	typedef void (Item::CallBack)(wxCommandEvent&);
private:

public:
	Item(void);
	void registerIn(wxFrame *parent,std::map<std::string,Container>&,AppConfig const& appConfig);

	void enable(wxCommandEvent &ev);
	virtual void readConfig(std::string const &graphicalResources)=0;
	void createMenu(wxFrame *parent);
	void createToolbarItem(std::map<std::string,Container>&containers,wxWindow*parent);
protected:
private:

public:///common parameters
	MenuData m_entry;
	long m_id;

///menu parameters
	std::vector<MenuData> m_path;

///toolbar parameters
	std::string m_longDoc;
	wxBitmap m_disabled,m_enabled;
	wxObject *m_unused;
	void (*m_callback)(Item*,wxCommandEvent&);
private:
};

PLUMA_PROVIDER_HEADER(Item)

#endif
