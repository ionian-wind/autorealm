#ifndef ITEM_H
#define ITEM_H

#include <memory>

#include "menuitem.h"

class Plugin;

class Item : public MenuItem
{
friend class Menu;
public:
	virtual ~Item();
	void associate(std::unique_ptr<Plugin> target);
protected:
	Item(boost::filesystem::path const &location);
private:

public:
protected:
	std::unique_ptr<Plugin> m_plugin;
private:
};

#endif // ITEM_H
