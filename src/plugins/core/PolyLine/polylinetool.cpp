#include "polylinetool.h"

#include <wx/image.h>

PolyLineTool::PolyLineTool(void)
:Item("polyline.cfg")
{
}

void PolyLineTool::readConfig(AppConfig const& config, FILE *file)
{
	m_callback=static_cast<void(Item::*)(wxCommandEvent&)>(&PolyLineTool::DumbMethod);
}

#include <wx/msgdlg.h>
void PolyLineTool::DumbMethod(wxCommandEvent& event)
{
	wxMessageBox("hello world","hello caption");
}

