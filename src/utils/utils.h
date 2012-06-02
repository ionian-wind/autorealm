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

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string>

#include <wx/bitmap.h>
#include <Pluma/Pluma.hpp>

#include "../gui/appconfig.h"

/** \brief open an image from disk if it exists
 *
 * \param fileName std::string const&
 * \return wxBitmap
 */
wxBitmap loadImage(std::string const & fileName);

//!\todo PlumaLack#1 implement a Provider::getProvider(std::string const &plugName) in pluma to remove dumb code here
//!\todo move me in Pluma
template <class T>
T* getProvider(pluma::Pluma & plumConf, std::string const& location, std::string const& pluginName)
{
	std::vector<T*> prevProviders, actualProviders;
	plumConf.getProviders(prevProviders);
	if(plumConf.load(location,pluginName))
	{ // register loaded provider
		decltype(actualProviders.size()) i=0;
		plumConf.getProviders(actualProviders);//!\todo PlumaLack#1 remove that
		//!\todo PlumaLack#1 remove that
		//Locate the provider newly loaded
		while(i<actualProviders.size() && prevProviders.end()!=std::find(prevProviders.begin(),prevProviders.end(),actualProviders[i]))
			++i;

		if(i<=actualProviders.size())
			return actualProviders[i];
	}
	return nullptr;
}

#endif // UTILS_H
