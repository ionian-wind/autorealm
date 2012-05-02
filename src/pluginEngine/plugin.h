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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <string>
#include <Pluma/Pluma.hpp>

class wxCommandEvent;

class Plugin
{
	public:
		Plugin(void);
		virtual void activator(wxCommandEvent&)=0;
		virtual ~Plugin();
	protected:
		static const std::string m_configFileName;
	private:
};

class PluginProvider: public pluma::Provider{
private:
    friend class pluma::Pluma;
    static const unsigned int PLUMA_INTERFACE_VERSION;
    static const unsigned int PLUMA_INTERFACE_LOWEST_VERSION;
    static const std::string PLUMA_PROVIDER_TYPE;
    std::string plumaGetType() const{ return PLUMA_PROVIDER_TYPE; }
public:
    unsigned int getVersion() const{ return PLUMA_INTERFACE_VERSION; }
	virtual Plugin* create() const = 0; //!\todo PlumaLack#2 send this method into pluma::Provider and make Provider a template?
	bool operator!=(PluginProvider const&other)const;
	virtual std::string const& getPluginName(void)const=0;
};

#endif // PLUGIN_H
