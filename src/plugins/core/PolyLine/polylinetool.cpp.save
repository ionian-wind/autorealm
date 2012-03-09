#include "polylinetool.h"

#include <wx/image.h>

void PolyLineTool::readConfig(std::string const &graphicalResources)
{
//	wxFrame::Bind(wxEVT_COMMAND_MENU_SELECTED, m_callback, m_parent, m_id);

	m_entry.help="help about polylinetool";
	m_entry.kind=wxITEM_NORMAL;
	m_entry.name="polylinetool";
	m_id=wxNewId();

	m_path.push_back(MenuData("Tool","tool menu",wxITEM_NORMAL));

	m_longDoc="long doc about polylinetool";
	m_disabled=wxNullBitmap;
	m_enabled=wxImage(graphicalResources+"png_files/toolbars/shape/tool-polycurve.png");

	m_callback=static_cast<void(Item::*)(wxCommandEvent&)>(&PolyLineTool::onClick);
}

#include <wx/msgdlg.h>

void PolyLineTool::onClick(wxCommandEvent& event)
{
	wxMessageDialog(NULL,"test");
}
