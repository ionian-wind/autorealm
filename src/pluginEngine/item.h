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

#include <string>
#include <vector>
#include <map>

#include <Pluma/Pluma.hpp>

#include "menudata.h"

class Container;
class AppConfig;
class MainFrame;

class Item
{
public:
protected:
private:

public:
	Item(void);
	void registerIn(MainFrame *parent,std::map<std::string,Container>&,AppConfig const& appConfig);

	void enable(void);
	void readConfig(std::string const &graphicalResources);
	void createMenu(void);
	void createToolbarItem(std::map<std::string,Container>&containers);
protected:
	wxMenu* findLastMenu(wxMenu *parent,std::vector<MenuData>::iterator &it);
	wxMenu* createMenuPath(wxMenu *parent,std::vector<MenuData>::iterator &it);
private:
	void DumbMethod(wxCommandEvent& event);

public:
protected:
	wxFrame * m_parent;
///common parameters
	MenuData m_entry;
	long m_id;

///menu parameters
	std::vector<MenuData> m_path;

///toolbar parameters
	std::string m_longDoc;
	wxObject *m_unused;
	void (Item::*m_callback)(wxCommandEvent&);
	wxBitmap m_disabled,m_enabled;
private:
};

PLUMA_PROVIDER_HEADER(Item)

#endif
