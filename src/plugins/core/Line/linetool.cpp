#include "linetool.h"

#include <wx/image.h>

LineTool::LineTool(void)
:Item("line.cfg")
{
}

void LineTool::readConfig(AppConfig const& config, FILE *file)
{
	m_callback=static_cast<ITEM_CALLBACK>(&LineTool::action);
}

#include <wx/msgdlg.h>
void LineTool::action(wxEvent& event)
{
	wxMessageBox("hello Line","hello caption");
}

