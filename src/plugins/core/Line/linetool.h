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

#ifndef LineTool_H
#define LineTool_H

#include <memory>

#include <pluginEngine/plugin.h>
#include <utils/textfile.h>

#include <wx/event.h>

class LineTool : public Plugin
{
	public:
		LineTool(void);
		virtual void readConfig(std::unique_ptr<TextFile> &file);
		virtual void action(wxEvent &);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(LineTool,Plugin)
#endif // INETOOL_H
