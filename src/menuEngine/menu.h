#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>

#include "menuitem.h"

class Menu : public MenuItem
{
public:
	virtual ~Menu();
protected:
	Menu(boost::filesystem::path const &location);
private:
public:
protected:
private:
	std::vector<std::unique_ptr<MenuItem>> m_leaves;
};

#endif // MENU_H
