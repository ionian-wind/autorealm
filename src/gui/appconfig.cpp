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

namespace po=boost::program_options;

AppConfig::AppConfig(void)
:m_datas(),m_defaultRendererTags()
{
	char **argv=App::GetInstance()->argv;
	int argc=App::GetInstance()->argc;
	//no decent default values?
	std::string config_filename(getUserConfigDir());
	config_filename+="/config";

	//commandline only
	po::options_description generic("Generic options");
	generic.add_options()
		("version,v","print version string")
		("help,h","produce help message")
		("config,c",po::value<std::string>(&config_filename)->default_value(config_filename),
			"name of a configuration file");

	std::string filler,border,menu,graphics,plugins,toolbars;
	//option provided by files or command-line
	po::options_description config_file("User configuration");
	config_file.add_options()
		("border",po::value<std::string>(&border),"default taglist to identify drawer used for borders and lines")
		("filler",po::value<std::string>(&filler),"default taglist to identify drawer used for filling shapes")
		("menubar", po::value<std::string>(&menu),"folder to look for menubar description")
		("toolbars", po::value<std::string>(&toolbars),"folder to look for toolbars description")
		("graphics", po::value<std::string>(&graphics),"folder to look for graphical resources")
		("plugins", po::value<std::string>(&plugins),"folder to look for plug-ins");
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

	//parse user configuration file
	readConfFile(config_filename,vm,config_file);

	//parse system configuration file
	config_filename=getSystemConfigDir();
	config_filename+="/config";
	readConfFile(config_filename,vm,config_file);

	if(vm.count("version"))
		; ///\todo

	if(vm.count("help"))
		std::cout << cmdline_options;

	m_defaultRendererTags[BORDER]=border;
	m_defaultRendererTags[FILLER]=filler;
	m_datas[MENU]=menu;
	m_datas[TOOLBARS]=toolbars;
	m_datas[GRP_RES]=graphics;
	m_datas[PLUGINS]=plugins;
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
