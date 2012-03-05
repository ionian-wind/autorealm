#include "polylinetool.h"

#include <wx/image.h>

void PolyLineTool::callback(wxCommandEvent& event)
{
}

void PolyLineTool::readConfig(std::string const &graphicalResources)
{
	m_entry.help="help about polylinetool";
	m_entry.kind=wxITEM_NORMAL;
	m_entry.name="polylinetool";
	m_id=wxNewId();

	m_path.push_back(MenuData("Tool","tool menu",wxITEM_NORMAL));

	m_longDoc="long doc about polylinetool";
	m_disabled=wxNullBitmap;
	m_enabled=wxImage(graphicalResources+"png_files/toolbars/shape/tool-polycurve.png");
}
