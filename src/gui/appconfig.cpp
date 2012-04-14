#include "appconfig.h"

AppConfig::AppConfig()
{
	//!\todo retrieve those informations from a configuration file
	std::string root="/home/berenger/prj/diff/autorealm/";

	m_configfiles=root+"config/";
	m_graphicalResources=root;
	m_pluginsConfig="plugins/";
}
