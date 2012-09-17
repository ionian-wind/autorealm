#ifndef TPROVIDER_H
#define TPROVIDER_H

#include <pluginEngine/pluginprovider.h>

template <typename Provided>
class TPluginProvider: public PluginProvider
{
public:
	Plugin * create(RenderWindow*w) const{ return new Provided(w); }
};

#endif // TPROVIDER_H
