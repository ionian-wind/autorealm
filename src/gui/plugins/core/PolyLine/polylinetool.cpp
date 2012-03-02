#include "polylinetool.h"

#include <wx/image.h>

PolyLineTool::PolyLineTool()
{
}

void PolyLineTool::callback(wxCommandEvent& event)
{
}

void PolyLineTool::readConfig(void)
{
	m_entry.help="help about polylinetool";
	m_entry.kind=wxITEM_NORMAL;
	m_entry.name="polylinetool";
	m_id=wxNewId();

	std::vector<MenuData> m_path;
	m_path.push_back(MenuData("Tool","tool menu",wxITEM_NORMAL));

	m_longDoc="long doc about polylinetool";
	m_disabled=wxNullBitmap;
	m_enabled=wxImage(_T("/home/berenger/prj/autorealm/png_files/heximage.png"));
}
