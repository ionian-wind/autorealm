#ifndef MENUITEMCONFIG_H
#define MENUITEMCONFIG_H

#include <string>
#include <stdio.h>
#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include <wx/menu.h>
#include <tree.h>

namespace fs=boost::filesystem;
namespace po=boost::program_options;

enum MenuKind
{
	SEPARATOR=wxITEM_SEPARATOR,
	NORMAL=wxITEM_NORMAL,
	CHECK=wxITEM_CHECK,
	RADIO=wxITEM_RADIO
};

class MenuItemConfig
{
	const fs::path m_path;
	std::string m_text;
	std::string m_desc;
	std::string m_plugin;
	MenuKind m_kind=NORMAL;
	bool m_showTitle=false;
	uint16_t m_id;

public:
	MenuItemConfig(fs::path const& rootDir);
	MenuItemConfig(MenuItemConfig && other);
	MenuItemConfig(MenuItemConfig const& other);
	std::string loc(void)const;
	std::string text(void)const;
	std::string desc(void)const;
	std::string plugin(void)const;
	MenuKind kind(void)const;
	bool showTitle(void)const;
	uint16_t id(void)const;
	void setId(uint16_t id);
};

typedef Node<MenuItemConfig> _Folder;
typedef Leaf<MenuItemConfig> _File;

std::istream& operator>>(std::istream& in, MenuKind& kind);
_Folder createTree(fs::path const& origin);
wxMenuBar* createMenuFromFolder(_Folder & origin);
wxMenu* createMenu(_Folder & origin);

#endif
