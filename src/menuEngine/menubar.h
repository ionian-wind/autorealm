#ifndef MENUBAR_H
#define MENUBAR_H

#include "menu.h"


class MenuBar : public Menu
{
	public:
		MenuBar(boost::filesystem::path const &location);
		virtual ~MenuBar();
	protected:
	private:
};

#endif // MENUBAR_H
