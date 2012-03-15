#include "linetool.h"

#include <wx/image.h>

LineTool::LineTool(void)
:Item("line.cfg")
{
}

void LineTool::readConfig(AppConfig const& config, FILE *file)
{
	m_callback=static_cast<void(Item::*)(wxCommandEvent&)>(&LineTool::DumbMethod);
}

#include <wx/msgdlg.h>
void LineTool::DumbMethod(wxCommandEvent& event)
{
	wxMessageBox("hello Line","hello caption");
}

