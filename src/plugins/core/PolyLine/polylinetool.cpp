#include "polylinetool.h"

#include <wx/image.h>
#include "gui/MainFrame.h"

PolyLineTool::PolyLineTool(void)
:Item("polyline.cfg")
{
}

void PolyLineTool::readConfig(AppConfig const& config, FILE *file)
{
	m_callback=static_cast<ITEM_CALLBACK>(&PolyLineTool::action);
}

void PolyLineTool::action(wxEvent&ev)
{
	wxMessageBox("hello world","hello caption");
}
