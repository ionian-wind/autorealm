#ifndef ITEM_H
#define ITEM_H

#include "menuitem.h"


class Item : public MenuItem
{
	friend class Menu;
	public:
		virtual ~Item();
	protected:
		Item(boost::filesystem::path const &location);
	private:
};

#endif // ITEM_H
