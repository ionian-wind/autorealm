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

class Item
{
public:
protected:
private:

public:
    /** \brief Default Ctor
     *	assign an id to m_id and initialize m_callback to make it easy to detect lack of initialization
     */
	Item(void);

    /** \brief create controls to use a plug-in and bind it's action
     * The plug-in add it's controls to it's parent's lists.
     * The location of several things will be given by the AppConfig object
     *
     * \param parent wxFrame* container which will own the plug-in controls
     * \param containers std::map<std::string,Container>& list of parent's plug-in
     * \param appConfig AppConfig const& configuration of the application
     * \return void
     *
     */
	void registerIn(wxFrame *parent,std::map<std::string,Container>&,AppConfig const& appConfig);

    /** \brief enable the plug-ins controls
     *	\throw std::logic_error if the m_callback member was not initialized
     */
	void enable(void);

    /** \brief read the plug-in's configuration
     * \param graphicalResources std::string const& path where data will be searched
     */
	void readConfig(AppConfig const& config);

    /** \brief create the plug-in's menu item entry
     *	The menu path will be created if it does not exist
     *	\throw std::runtime_error if the path is empty (probably a configuration's problem)
     *	\throw std::runtime_error if the just created menu is not found (should never happen, but I prefer to check the most thing possible from wxWidgets)
     */
	void createMenu(void);

    /** \brief create the plug-in's toolbar item and bind it to the corresponding toolbar
	 *	\note the toolbar is created if it does not exists
     *
     * \param containers std::map<std::string, Container>& list of existing toolbars
     */
	void createToolbarItem(std::map<std::string,Container>&containers);

protected:
    /** \brief follow the menu tree to find the last sub-menu corresponding with the plug-in path
     * \note this method is recursive
     * \param parent wxMenu* menu in which the next corresponding child will be searched
     * \param it std::vector<MenuData>::iterator& iterator to the plug-in's searched entry
     * \return wxMenu* found item
     */
	wxMenu* findLastMenu(wxMenu *parent,std::vector<MenuData>::iterator &it);

    /** \brief create the absent tree where to insert the menu item which will represent the plug-in
     * \note this method is recursive
     * \param parent wxMenu* menu in which the next corresponding child will be created
     * \param it std::vector<MenuData>::iterator& iterator to the plug-in's created entry
     * \return wxMenu* made item
     */
	wxMenu* createMenuPath(wxMenu *parent,std::vector<MenuData>::iterator &it);

private:
    /** \brief Dumb, Stupid, and Useless method made for testing, while the plug-in architecture does not work
     *	\todo Remove me
     */
	void DumbMethod(wxCommandEvent& event);

    /** \brief encapsulate the wxWidgets wxMenu* wxMenu::GetMenu(int) and add some error checking
     * \throw std::runtime_error if the menu found is null
     * \param id int id of the menu to retrieve
     * \return wxMenu* address of the retrieved menu
     */
	wxMenu *GetMenu(int id);

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
