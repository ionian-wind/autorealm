#include "polylinetool.h"

#include <wx/image.h>

PolyLineTool::PolyLineTool()
{
	wxAuiToolBar *toolbarContainer;
	int toolId=0;//ID_AUITOOLBARITEMPOLYLINE;
	std::string toolName("PolyLine");
	wxBitmap bitmapEnabled(wxImage(_T("png_files/toolbars/shape/tool-polyline.png")));
	wxBitmap bitmapDisabled(wxNullBitmap);
	wxItemKind kind;

//    toolbarContainer->AddTool(toolId, toolName, bitmapEnabled, bitmapDisabled, kind, toolName, toolName, NULL);

	wxMenuItem *menuItem;
//    menuItem = new wxMenuItem(menuContainer, toolId, toolName, toolName, kind);


//    Connect(toolId,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&PolyLineTool::callback);

	//ctor
}

void PolyLineTool::callback(wxCommandEvent& event)
{
}

//void PolyLineTool::enable(void)
//{
//}
//
//void PolyLineTool::disable(void)
//{
//}
