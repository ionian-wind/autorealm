#ifndef TDRAWERPROVIDER_H
#define TDRAWERPROVIDER_H

#include <vector>
#include <string>

#include "pluginprovider.h"
#include "drawer.h"

template <typename Renderer>
class TDrawerProvider: public PluginProvider
{
public:
	typedef std::vector<std::string> TagList;
	TagList m_tagList;

	Plugin * create(RenderWindow*w) const
	{
		return new Drawer(w, std::unique_ptr<Renderer>(new Renderer()), m_tagList);
	}
};


#endif // TDRAWERPROVIDER_H
