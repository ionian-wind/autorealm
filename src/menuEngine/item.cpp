#include "item.h"

Item::Item(boost::filesystem::path const &location)
:MenuItem(), m_plugin()
{
}

Item::~Item()
{
	//dtor
}

void Item::associate(std::unique_ptr<Plugin> target)
{
	m_plugin.reset(target);
}
