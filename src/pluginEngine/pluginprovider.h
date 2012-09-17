#ifndef PLUGINPROVIDER_H
#define PLUGINPROVIDER_H

#include <Pluma/Pluma.hpp>
#include <Pluma/Connector.hpp>

#include "plugin.h"

class PluginProvider: public pluma::Provider
{
private:
	friend class pluma::Pluma;
	static const unsigned int PLUMA_INTERFACE_VERSION;
	static const unsigned int PLUMA_INTERFACE_LOWEST_VERSION;
	static const std::string PLUMA_PROVIDER_TYPE;
	std::string plumaGetType() const{ return PLUMA_PROVIDER_TYPE; }
public:
	unsigned int getVersion() const{ return PLUMA_INTERFACE_VERSION; }
	virtual Plugin* create(RenderWindow*w) const = 0;
};

#endif // PLUGINPROVIDER_H
