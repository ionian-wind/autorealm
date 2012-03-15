#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <string>

class AppConfig
{
	public:
        /** \brief
         * \todo retrieve data from a configuration file
         */
		AppConfig();
		std::string m_graphicalResources;
		std::string m_configfiles;
		std::string m_pluginsConfig;
	protected:
	private:
};

#endif // APPCONFIG_H
