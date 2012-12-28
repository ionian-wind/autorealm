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

#include "appconfig.h"

#include "app.h"
#include "utils/utils.h"
#include <boost/program_options.hpp>
#include <fstream>
#include <stdexcept>
#include <wx/msgdlg.h>

namespace po=boost::program_options;

AppConfig::AppConfig(void)
:m_datas(),m_defaultRendererTags()
{
	char **argv=App::GetInstance()->argv;
	int argc=App::GetInstance()->argc;
	//no decent default values?
	std::string config_filename(getUserConfigDir());

	//commandline only
	po::options_description generic("Generic options");
	generic.add_options()
		("version,v","print version string")
		("help,h","produce help message")
		("config,c",po::value<std::string>(&config_filename)->default_value(config_filename),
			"name of a configuration file");

	std::string filler,border; ///\todo remove those temp vars
	//option provided by files or command-line
	po::options_description config_file("User configuration");
	config_file.add_options()
		("border",po::value<std::string>(&border),"default taglist to identify drawer used for borders and lines")
		("filler",po::value<std::string>(&filler),"default taglist to identify drawer used for filling shapes")
		("menubar", po::value<std::string>(&m_datas[MENU]),"folder to look for menubar description")
		("toolbars", po::value<std::string>(&m_datas[TOOLBARS]),"folder to look for toolbars description")
		("graphics", po::value<std::string>(&m_datas[GRP_RES]),"folder to look for graphical resources")
		("plugins", po::value<std::string>(&m_datas[PLUGINS]),"folder to look for plug-ins");
		("input-file", po::value<std::vector<std::string>>(), "files to open at start-up");

	//command-line declaration and settings
	po::options_description cmdline_options;
	cmdline_options.add(generic).add(config_file);

	//user configuration file declaration and settings
	po::options_description conf_file;
	conf_file.add(config_file);

	po::positional_options_description p;
	p.add("input-file",-1);
	po::variables_map vm;

	//parse command line
	store(po::command_line_parser(argc,argv).
		options(cmdline_options).positional(p).run(),vm);
	notify(vm);
	if(vm.count("version"))
		; ///\todo
	if(vm.count("help"))
		std::cout << cmdline_options;


	//parse user configuration file
	if(!config_filename.empty())
		readConfFile(config_filename,vm,config_file);

	try
	{
		//parse system configuration file
		config_filename=getSystemConfigDir();
	}catch(std::runtime_error &e)
	{
		wxMessageBox(std::string("An exception has occured.\nAutoREALM might recover from it, or might crash latter. Here is the error:\n")+e.what(), "Non-fatal exception");
	}
	readConfFile(config_filename,vm,config_file);

	m_defaultRendererTags[BORDER]=border;
	m_defaultRendererTags[FILLER]=filler;

	// check for errors
	std::string configErrors; ///\todo improve those error messages
	for(std::string s:m_defaultRendererTags)
		if(s.empty())
			configErrors+="A configuration field for renderers is empty.";
	for(std::string s:m_datas)
		if(s.empty())
			configErrors+="A configuration field for paths is empty.";
	if(!configErrors.empty())
		throw std::runtime_error(configErrors);

}

std::string AppConfig::buildPath(INFO info)
{
 	assert(LASTINDEX>=info);
	return GetInstance().m_datas[info];
}

Render::TagList AppConfig::getRenderer(RENDERER renderer)
{
	assert(LASTRENDERER>=renderer);
	return GetInstance().m_defaultRendererTags[renderer];
}

void AppConfig::readConfFile(std::string const& file, boost::program_options::variables_map &vm,boost::program_options::options_description const& optionSet)
{
	std::ifstream ifs(file);
	if(!ifs)
		throw std::runtime_error("unable to find configuration file: "+file);

	store(parse_config_file(ifs,optionSet),vm);
	notify(vm);
}
