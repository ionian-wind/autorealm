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

#include <boost/filesystem.hpp>

#include <pluginEngine/plugin.h>
#include <pluginEngine/drawer.h>
#include <pluginEngine/pluginprovider.h>

#include "app.h"
#include "mainframe.h"
#include "renderwindow.h"

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

			m_menuTree.reset(new Menu(boost::filesystem::path(AppConfig::buildPath(AppConfig::INFO::MENU))));
			m_actionPlugIn.acceptProviderType<PluginProvider>();
			//create the notebook and add it an empty page
			loadRequestedPlugins();
			m_app->getActive()->setDefaultRenderers();
			m_menuTree->create();
			m_app->SetMenuBar(m_menuTree->getMenuBar());

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

App::App(void)
{
	for(std::pair<ID,Plugin*> i : m_plugins)
		delete i.second;

	wxCommandEvent e;
	e.SetId(0);
	changeSelectedPlugin(e);
}

void App::loadRequestedPlugins(void)
{
	for(Component<MenuConverter> &i : *m_menuTree) //only browse leaves
	{
		std::string plugName = i.getPluginName();
		AssocIDs::iterator jt = m_buttonIDs.find(plugName);

		if(jt == m_buttonIDs.end()) // plugin is not loaded? Try to load it.
		{
			assert(!m_actionPlugIn.isLoaded(plugName));///\note should never load twice the same plugin. Could be in pluma...
			PluginProvider *plugProvider = getProvider<PluginProvider>(m_actionPlugIn, AppConfig::buildPath(AppConfig::PLUGINS), plugName);

			if(nullptr != plugProvider)
			{
				ID tmpid(m_buttonIDs[plugName]);// avoid searching twice in the map
				Plugin* tmpplug=plugProvider->create(m_app->getActive());
				m_plugins[tmpid]=tmpplug;
				i.setID(tmpid);
			}
			else
				i.disable();
		}

		if(i.isEnabled())
		{
			jt = m_buttonIDs.find(plugName);

			if(jt != m_buttonIDs.end()) // plugin loaded? Bind it.
				Bind(wxEVT_COMMAND_MENU_SELECTED, &App::changeSelectedPlugin, this, jt->second, jt->second);
		}
	}
}

void App::changeSelectedPlugin(wxCommandEvent &event)
{
	static int oldId = 0;

	if(oldId)
		m_plugins[oldId]->removeEventManager();

	oldId = event.GetId();
	if(oldId)
		m_plugins[oldId]->installEventManager();
}
