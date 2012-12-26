#ifndef TOOLBARITEMCONFIG_H
#define TOOLBARITEMCONFIG_H

#include <string>
#include <stdio.h>
#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "wxadapter.h"
#include <wx/menu.h>
#include <tree.h>

namespace fs=boost::filesystem;
namespace po=boost::program_options;

class ToolbarItemConfig
{
	const fs::path m_path;
	std::string m_label;
	std::string m_bmp;
	std::string m_desc;
	std::string m_plugin;
	ItemKind m_kind=NORMAL;
	uint16_t m_id;

public:
	ToolbarItemConfig(fs::path const& rootDir);
	ToolbarItemConfig(ToolbarItemConfig && other);
	ToolbarItemConfig(ToolbarItemConfig const& other);
	std::string label(void)const;
	std::string bmp(void)const;
	std::string desc(void)const;
	std::string plugin(void)const;
	ItemKind kind(void)const;
	uint16_t id(void)const;
	void setId(uint16_t id);
};

#include <wx/aui/framemanager.h>
#include <wx/aui/auibar.h>
#include <wx/aui/framemanager.h>

void buildToolbars(wxAuiManager &mgr,Node<ToolbarItemConfig> & origin, wxWindow *parent);
wxAuiToolBar* buildPaneComponents(Node<ToolbarItemConfig> &data, wxWindow *parent);
wxAuiPaneInfo buildPaneInfo(Leaf<ToolbarItemConfig> &data);

#endif
