#ifndef MENU_DATA_H
#define MENU_DATA_H

#include <string>

#include <wx/frame.h>

struct MenuData
{
	MenuData(std::string const &nAME, std::string const& hELP, wxItemKind const kIND)
	:kind(kIND),help(hELP),name(nAME){}

	MenuData(void)
	:kind(),help(),name(){}

	wxItemKind kind;
	std::string help;
	std::string name;
};

#endif
