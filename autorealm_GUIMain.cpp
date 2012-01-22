/***************************************************************
 * Name:      autorealm_GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     Morel Berenger
 * Created:   2011-12-15
 * Copyright:  GPL
 * License:
 * autorealm - A software to create maps
 * Copyright (C) 2011 Morel Berenger
 *
 *This file is part of autorealm.
 *
 *	autorealm is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	autorealm is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with autorealm.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************/

#include "autorealm_GUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(autorealm_GUIFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(autorealm_GUIFrame)
const long autorealm_GUIFrame::ID_AUITOOLBARITEMFREEHAND = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMLINE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPOLYLINE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMCURVE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPOLYCURVE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARSHAPE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMALIGN = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMFLIP = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSKEW = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMROTATE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSCALE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMMOVE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMROT90 = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMROT45 = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMARRAY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMORDER = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARTRANSFORM = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMTOGGLEOVERLAY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMGRAVITY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMGRIDSNAP = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMLINEGRAVITY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMROTATESNAP = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARGRIDSETTINGS = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMMAINCOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMFILLCOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMFILLPATTERN = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMTEXTOUTLINECOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMBACKGROUNDCOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMGRIDCOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSHOWCOLORMANAGER = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMTRANSLATECOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMINVERSETRANSLATECOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARCOLOR = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMZOOM = wxNewId();
const long autorealm_GUIFrame::ID_COMBOBOXZOOM = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARZOOM = wxNewId();
const long autorealm_GUIFrame::ID_LISTBOXNAMES = wxNewId();
const long autorealm_GUIFrame::ID_LISTVIEWCONTENT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARPAGES = wxNewId();
const long autorealm_GUIFrame::ID_STATICTEXTWIDTH = wxNewId();
const long autorealm_GUIFrame::ID_SPINCTRLWIDTH = wxNewId();
const long autorealm_GUIFrame::ID_STATICTEXTHEIGHT = wxNewId();
const long autorealm_GUIFrame::ID_SPINCTRLHEIGHT = wxNewId();
const long autorealm_GUIFrame::ID_CHECKBOXASPECT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARSIZE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSELECT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMOPEN = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSAVE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPAN = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMRULER = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMMEASUREMENTSTRING = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMREPAINT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMUNDO = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMREDO = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMREADONLY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBAR9GENERAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSINGLEICON = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSQUAREPLACEMENT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMDIAMONDPLACEMENT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMRANDOMPLACEMENT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMDEFINESYMBOL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSYMBOLLIBRARY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARPLACEMENT = wxNewId();
const long autorealm_GUIFrame::ID_CHOICESTART = wxNewId();
const long autorealm_GUIFrame::ID_CHOICEBODY = wxNewId();
const long autorealm_GUIFrame::ID_CHOICEEND = wxNewId();
const long autorealm_GUIFrame::ID_SPINCTRLTHICKNESS = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARLINESTYLE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSENDBACK = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSENDBACKWARD = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSENDFORWARD = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSENDFRONT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPASTE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMCOPY = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMCUT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMDELETE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSCALPEL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMGLUE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBAREDITING = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMFREEHANDFRACTAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMLINEFRACTAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPOLYLINEFRACTAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMCURVEFRACTAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPOLYCURVEFRACTAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARFRACTAL = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMRECTANGLE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMCIRCLE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPOLYGON = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMARC = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMROSETTECHARTLINES = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMTEXT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMCURVEDTEXT = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMHYPERLINKPOPUP = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMGROUP = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMUNGROUP = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMDECOMPOSE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARDRAWING = wxNewId();
const long autorealm_GUIFrame::ID_SCROLLEDWINDOWMAP1 = wxNewId();
const long autorealm_GUIFrame::ID_AUINOTEBOOKWORKSPACE = wxNewId();
const long autorealm_GUIFrame::ID_STATICBOXFRACTALSETTINGS = wxNewId();
const long autorealm_GUIFrame::ID_STATICBITMAPROUGHNESS = wxNewId();
const long autorealm_GUIFrame::ID_SLIDERROUGHNESS = wxNewId();
const long autorealm_GUIFrame::ID_STATICBITMAPACORN = wxNewId();
const long autorealm_GUIFrame::ID_SPINCTRLSEED = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARFRACTALSETTINGS = wxNewId();
const long autorealm_GUIFrame::ID_STATICBOXGRAPHPAPER = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMNOGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMSQUAREGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMHEXGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMRHEXGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMTRIANGLEGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMDIAMONDGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMHDIAMONDGRID = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARITEMPOLARGRID = wxNewId();
const long autorealm_GUIFrame::ID_TEXTCTRLGRIDSIZE = wxNewId();
const long autorealm_GUIFrame::ID_STATICTEXTDIMENSION = wxNewId();
const long autorealm_GUIFrame::ID_STATICBITMAPGRIDSIZE = wxNewId();
const long autorealm_GUIFrame::ID_SLIDERGRIDSIZE = wxNewId();
const long autorealm_GUIFrame::ID_STATICBITMAPBOLDGRID = wxNewId();
const long autorealm_GUIFrame::ID_SPINCTRLSECONDARYGRID = wxNewId();
const long autorealm_GUIFrame::ID_CHOICEPRIMGRIDSTYLE = wxNewId();
const long autorealm_GUIFrame::ID_CHOICESECGRIDSTYLE = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARGRAPHPAPER = wxNewId();
const long autorealm_GUIFrame::ID_STATICBOXICONSETTINGS = wxNewId();
const long autorealm_GUIFrame::ID_STATICBITMAPICONSIZE = wxNewId();
const long autorealm_GUIFrame::ID_SLIDERICONSIZE = wxNewId();
const long autorealm_GUIFrame::ID_STATICBITMAPDENSITY = wxNewId();
const long autorealm_GUIFrame::ID_SLIDERICONSPREAD = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARICONSETTINGS = wxNewId();
const long autorealm_GUIFrame::ID_COMBOBOXACTIVE = wxNewId();
const long autorealm_GUIFrame::ID_CHECKLISTBOXLIST = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBAROVERLAY = wxNewId();
const long autorealm_GUIFrame::ID_CHECKLISTBOXPUSHPINS = wxNewId();
const long autorealm_GUIFrame::ID_AUITOOLBARPUSHPINS = wxNewId();
const long autorealm_GUIFrame::idMenuNew = wxNewId();
const long autorealm_GUIFrame::idMenuOpen = wxNewId();
const long autorealm_GUIFrame::idMenuReopen = wxNewId();
const long autorealm_GUIFrame::idMenuSave = wxNewId();
const long autorealm_GUIFrame::idMenuSaveAs = wxNewId();
const long autorealm_GUIFrame::idMenuInsert = wxNewId();
const long autorealm_GUIFrame::idMenuPrint = wxNewId();
const long autorealm_GUIFrame::idMenuPrintSetup = wxNewId();
const long autorealm_GUIFrame::idMenuProperties = wxNewId();
const long autorealm_GUIFrame::idMenuQuit = wxNewId();
const long autorealm_GUIFrame::idMenuUndo = wxNewId();
const long autorealm_GUIFrame::idMenuRedo = wxNewId();
const long autorealm_GUIFrame::idMenuCut = wxNewId();
const long autorealm_GUIFrame::idMenuCopy = wxNewId();
const long autorealm_GUIFrame::idMenuPaste = wxNewId();
const long autorealm_GUIFrame::idMenuDelete = wxNewId();
const long autorealm_GUIFrame::idMenuSelectAll = wxNewId();
const long autorealm_GUIFrame::idMenuSelectNone = wxNewId();
const long autorealm_GUIFrame::idMenuUseSelectionTool = wxNewId();
const long autorealm_GUIFrame::idMenuUsePanningTool = wxNewId();
const long autorealm_GUIFrame::idMenuZoomIn = wxNewId();
const long autorealm_GUIFrame::idMenuZoomOut = wxNewId();
const long autorealm_GUIFrame::idMenuFit = wxNewId();
const long autorealm_GUIFrame::idMenu10 = wxNewId();
const long autorealm_GUIFrame::idMenu25 = wxNewId();
const long autorealm_GUIFrame::idMenu50 = wxNewId();
const long autorealm_GUIFrame::idMenu75 = wxNewId();
const long autorealm_GUIFrame::idMenu100 = wxNewId();
const long autorealm_GUIFrame::idMenu150 = wxNewId();
const long autorealm_GUIFrame::idMenu200 = wxNewId();
const long autorealm_GUIFrame::idMenu300 = wxNewId();
const long autorealm_GUIFrame::idMenu400 = wxNewId();
const long autorealm_GUIFrame::idMenu500 = wxNewId();
const long autorealm_GUIFrame::idMenuCustomZoom = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEMZOOM = wxNewId();
const long autorealm_GUIFrame::idMenuShowAll = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEMREADONLY = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEMSAVEVIEW = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEMDELETEVIEW = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM1 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM2 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM3 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM4 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM5 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM6 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM7 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM8 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM10 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM11 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM12 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM13 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM14 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM15 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM9 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM17 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM18 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM19 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM16 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM20 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM21 = wxNewId();
const long autorealm_GUIFrame::ID_MENUITEM22 = wxNewId();
const long autorealm_GUIFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(autorealm_GUIFrame,wxFrame)
    //(*EventTable(autorealm_GUIFrame)
    //*)
END_EVENT_TABLE()

autorealm_GUIFrame::autorealm_GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(autorealm_GUIFrame)
    wxMenuItem* MenuItem2;
    wxMenuBar* MenuBar;
    wxMenu* MenuFile;
    wxMenuItem* MenuItemExit;
    wxMenu* MenuHelp;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1268,379));
    AuiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    AuiToolBarShape = new wxAuiToolBar(this, ID_AUITOOLBARSHAPE, wxPoint(68,144), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarShape->AddTool(ID_AUITOOLBARITEMFREEHAND, _("FreeHand"), wxBitmap(wxImage(_T("png_files/toolbars/shape/tool-freehand.png"))), wxNullBitmap, wxITEM_NORMAL, _("FreeHand"), wxEmptyString, NULL);
    AuiToolBarShape->AddTool(ID_AUITOOLBARITEMLINE, _("Line"), wxBitmap(wxImage(_T("png_files/toolbars/shape/tool-line.png"))), wxNullBitmap, wxITEM_NORMAL, _("Line"), wxEmptyString, NULL);
    AuiToolBarShape->AddTool(ID_AUITOOLBARITEMPOLYLINE, _("PolyLine"), wxBitmap(wxImage(_T("png_files/toolbars/shape/tool-polyline.png"))), wxNullBitmap, wxITEM_NORMAL, _("PolyLine"), wxEmptyString, NULL);
    AuiToolBarShape->AddTool(ID_AUITOOLBARITEMCURVE, _("Curve"), wxBitmap(wxImage(_T("png_files/toolbars/shape/tool-curve.png"))), wxNullBitmap, wxITEM_NORMAL, _("Curve"), wxEmptyString, NULL);
    AuiToolBarShape->AddTool(ID_AUITOOLBARITEMPOLYCURVE, _("PolyCurve"), wxBitmap(wxImage(_T("png_files/toolbars/shape/tool-polycurve.png"))), wxNullBitmap, wxITEM_NORMAL, _("PolyCurve"), wxEmptyString, NULL);
    AuiToolBarShape->Realize();
    AuiManager->AddPane(AuiToolBarShape, wxAuiPaneInfo().Name(_T("PaneShape")).ToolbarPane().Caption(_("Shape")).PinButton().Layer(10).Position(1).Top().Gripper());
    AuiToolBarTransform = new wxAuiToolBar(this, ID_AUITOOLBARTRANSFORM, wxPoint(139,271), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMALIGN, _("Align"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-align.png"))), wxNullBitmap, wxITEM_NORMAL, _("Align"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMFLIP, _("Flip"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-flip.png"))), wxNullBitmap, wxITEM_NORMAL, _("Flip"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMSKEW, _("Skew"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-skew.png"))), wxNullBitmap, wxITEM_NORMAL, _("Skew"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMROTATE, _("Rotate"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-rotate.png"))), wxNullBitmap, wxITEM_NORMAL, _("Rotate"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMSCALE, _("Scale"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-scale.png"))), wxNullBitmap, wxITEM_NORMAL, _("Scale"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMMOVE, _("Move"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-move.png"))), wxNullBitmap, wxITEM_NORMAL, _("Move"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMROT90, _("Rotate 90°"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-rotate90.png"))), wxNullBitmap, wxITEM_NORMAL, _("Rotate 90°"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMROT45, _("Rotate 45°"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-rotate45.png"))), wxNullBitmap, wxITEM_NORMAL, _("Rotate 45°"), wxEmptyString, NULL);
    AuiToolBarTransform->AddSeparator();
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMARRAY, _("Array"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-array.png"))), wxNullBitmap, wxITEM_NORMAL, _("Array"), wxEmptyString, NULL);
    AuiToolBarTransform->AddTool(ID_AUITOOLBARITEMORDER, _("Order"), wxBitmap(wxImage(_T("png_files/toolbars/transform/tool-order.png"))), wxNullBitmap, wxITEM_NORMAL, _("Order"), wxEmptyString, NULL);
    AuiToolBarTransform->Realize();
    AuiManager->AddPane(AuiToolBarTransform, wxAuiPaneInfo().Name(_T("Transform")).ToolbarPane().Caption(_("Transform")).PinButton().Layer(10).Position(6).Left().Gripper());
    AuiToolBarGridSettings = new wxAuiToolBar(this, ID_AUITOOLBARGRIDSETTINGS, wxPoint(68,144), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarGridSettings->AddTool(ID_AUITOOLBARITEMTOGGLEOVERLAY, _("Toggle Overlay Tags"), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-overlay-tags.png"))), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-overlay-tags.png"))), wxITEM_CHECK, _("Toggle Overlay Tags"), wxEmptyString, NULL);
    AuiToolBarGridSettings->AddTool(ID_AUITOOLBARITEMGRID, _("Design Grid"), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-design-grid.png"))), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-design-grid.png"))), wxITEM_CHECK, _("Design Grid"), wxEmptyString, NULL);
    AuiToolBarGridSettings->AddTool(ID_AUITOOLBARITEMGRAVITY, _("Toggle Gravity Snap"), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-gravity-snap-light.png"))), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-gravity-snap-dark.png"))), wxITEM_CHECK, _("Toggle Gravity Snap"), wxEmptyString, NULL);
    AuiToolBarGridSettings->AddTool(ID_AUITOOLBARITEMGRIDSNAP, _("Toggle Grid Snap"), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-grid-snap-light.png"))), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-grid-snap-dark.png"))), wxITEM_CHECK, _("Toggle Grid Snap"), wxEmptyString, NULL);
    AuiToolBarGridSettings->AddTool(ID_AUITOOLBARITEMLINEGRAVITY, _("Toggle Gravity Snap Along Lines And Curves"), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-gravity-snap-along-lines-and-curves-light.png"))), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-toggle-gravity-snap-along-lines-and-curves-dark.png"))), wxITEM_CHECK, _("Toggle Gravity Snap Along Lines And Curves"), wxEmptyString, NULL);
    AuiToolBarGridSettings->AddTool(ID_AUITOOLBARITEMROTATESNAP, _("Rotate Snapped Objects"), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-rotate-snapped-objects.png"))), wxBitmap(wxImage(_T("png_files/toolbars/grid_settings/tool-rotate-snapped-objects.png"))), wxITEM_CHECK, _("Rotate Snapped Objects"), wxEmptyString, NULL);
    AuiToolBarGridSettings->Realize();
    AuiManager->AddPane(AuiToolBarGridSettings, wxAuiPaneInfo().Name(_T("Grid Settings")).ToolbarPane().Caption(_("GridSettings")).PinButton().Layer(10).Position(5).Left().Gripper());
    AuiToolBarColor = new wxAuiToolBar(this, ID_AUITOOLBARCOLOR, wxPoint(182,101), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMMAINCOLOR, _("Main color"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Main color"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMFILLCOLOR, _("Fill Color"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Fill Color"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMFILLPATTERN, _("Fill Pattern"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Fill Pattern"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMTEXTOUTLINECOLOR, _("Text Outline Color"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Text Outline Color"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMBACKGROUNDCOLOR, _("Background Color"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Background Color"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMGRIDCOLOR, _("Grid Color"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, _("Grid Color"), wxEmptyString, NULL);
    AuiToolBarColor->AddSeparator();
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMSHOWCOLORMANAGER, _("Show Color Translation Manager"), wxBitmap(wxImage(_T("png_files/toolbars/color/tool-show-color-translation-manager.png"))), wxNullBitmap, wxITEM_NORMAL, _("Show Color Translation Manager"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMTRANSLATECOLOR, _("Translate Color"), wxBitmap(wxImage(_T("png_files/toolbars/color/tool-translate-color.png"))), wxNullBitmap, wxITEM_NORMAL, _("Translate Color"), wxEmptyString, NULL);
    AuiToolBarColor->AddTool(ID_AUITOOLBARITEMINVERSETRANSLATECOLOR, _("Inverse Translate Color"), wxBitmap(wxImage(_T("png_files/toolbars/color/tool-inverse-translate-color.png"))), wxNullBitmap, wxITEM_NORMAL, _("Inverse Translate Color"), wxEmptyString, NULL);
    AuiToolBarColor->Realize();
    AuiManager->AddPane(AuiToolBarColor, wxAuiPaneInfo().Name(_T("PaneColor")).ToolbarPane().Caption(_("Color")).PinButton().Layer(10).Position(2).Top().Resizable().Gripper());
    AuiToolBarZoom = new wxAuiToolBar(this, ID_AUITOOLBARZOOM, wxPoint(206,126), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    ComboBoxZoom = new wxComboBox(AuiToolBarZoom, ID_COMBOBOXZOOM, wxEmptyString, wxPoint(58,22), wxSize(57,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOXZOOM"));
    ComboBoxZoom->SetToolTip(_("Zoom Percentage"));
    AuiToolBarZoom->AddTool(ID_AUITOOLBARITEMZOOM, _("Zoom"), wxBitmap(wxImage(_T("png_files/toolbars/zoom/tool-zoom.png"))), wxNullBitmap, wxITEM_NORMAL, _("Zoom"), wxEmptyString, NULL);
    AuiToolBarZoom->AddControl(ComboBoxZoom, _("Zoom"));
    AuiToolBarZoom->Realize();
    AuiManager->AddPane(AuiToolBarZoom, wxAuiPaneInfo().Name(_T("Zoom")).ToolbarPane().Caption(_("Zoom")).PinButton().Layer(5).Position(3).Top().Gripper());
    AuiToolBarPages = new wxAuiToolBar(this, ID_AUITOOLBARPAGES, wxPoint(14,24), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    ListBoxNames = new wxListBox(AuiToolBarPages, ID_LISTBOXNAMES, wxPoint(48,11), wxSize(142,57), 0, 0, wxVSCROLL, wxDefaultValidator, _T("ID_LISTBOXNAMES"));
    ListViewContent = new wxListView(AuiToolBarPages, ID_LISTVIEWCONTENT, wxPoint(156,34), wxDefaultSize, 0, wxDefaultValidator, _T("ID_LISTVIEWCONTENT"));
    AuiToolBarPages->AddControl(ListBoxNames, _("Item label"));
    AuiToolBarPages->AddControl(ListViewContent, _("Item label"));
    AuiToolBarPages->Realize();
    AuiManager->AddPane(AuiToolBarPages, wxAuiPaneInfo().Name(_T("Pages")).ToolbarPane().Caption(_("Pages")).Layer(10).Position(12).Bottom().Gripper());
    AuiToolBarSize = new wxAuiToolBar(this, ID_AUITOOLBARSIZE, wxPoint(196,130), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    StaticTextWidth = new wxStaticText(AuiToolBarSize, ID_STATICTEXTWIDTH, _("X"), wxPoint(54,15), wxDefaultSize, 0, _T("ID_STATICTEXTWIDTH"));
    SpinCtrlWidth = new wxSpinCtrl(AuiToolBarSize, ID_SPINCTRLWIDTH, _T("0"), wxPoint(83,9), wxSize(51,25), 0, 0, 100, 0, _T("ID_SPINCTRLWIDTH"));
    SpinCtrlWidth->SetValue(_T("0"));
    StaticTextHeight = new wxStaticText(AuiToolBarSize, ID_STATICTEXTHEIGHT, _("Y"), wxPoint(183,11), wxDefaultSize, 0, _T("ID_STATICTEXTHEIGHT"));
    SpinCtrlHeight = new wxSpinCtrl(AuiToolBarSize, ID_SPINCTRLHEIGHT, _T("0"), wxPoint(241,12), wxSize(54,25), 0, 0, 100, 0, _T("ID_SPINCTRLHEIGHT"));
    SpinCtrlHeight->SetValue(_T("0"));
    CheckBoxAspect = new wxCheckBox(AuiToolBarSize, ID_CHECKBOXASPECT, _("Aspect"), wxPoint(299,11), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOXASPECT"));
    CheckBoxAspect->SetValue(true);
    AuiToolBarSize->AddControl(StaticTextWidth, _("X"));
    AuiToolBarSize->AddControl(SpinCtrlWidth, _("Witdh"));
    AuiToolBarSize->AddControl(StaticTextHeight, _("Y"));
    AuiToolBarSize->AddControl(SpinCtrlHeight, _("Height"));
    AuiToolBarSize->AddControl(CheckBoxAspect, _("Aspect"));
    AuiToolBarSize->Realize();
    AuiManager->AddPane(AuiToolBarSize, wxAuiPaneInfo().Name(_T("Size")).ToolbarPane().Caption(_("Size")).Layer(10).Position(11).Bottom().Gripper());
    AuiToolBarGeneral = new wxAuiToolBar(this, ID_AUITOOLBAR9GENERAL, wxPoint(187,130), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMSELECT, _("Select"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-select.png"))), wxNullBitmap, wxITEM_NORMAL, _("Select"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMOPEN, _("Open a map"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-open.png"))), wxNullBitmap, wxITEM_NORMAL, _("Open a map"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMSAVE, _("Save"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-save.png"))), wxNullBitmap, wxITEM_NORMAL, _("Save"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddSeparator();
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMPAN, _("Pan"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-pan.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pan"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMRULER, _("Ruler"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-ruler.png"))), wxNullBitmap, wxITEM_NORMAL, _("Ruler"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMMEASUREMENTSTRING, _("Measurement string"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-measurement-string.png"))), wxNullBitmap, wxITEM_NORMAL, _("Measurement string"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMREPAINT, _("Repaint"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-repaint.png"))), wxNullBitmap, wxITEM_NORMAL, _("Repaint"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddSeparator();
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMUNDO, _("Undo"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-undo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Undo"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMREDO, _("Redo"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-redo.png"))), wxNullBitmap, wxITEM_NORMAL, _("Redo"), wxEmptyString, NULL);
    AuiToolBarGeneral->AddSeparator();
    AuiToolBarGeneral->AddTool(ID_AUITOOLBARITEMREADONLY, _("Read-Only"), wxBitmap(wxImage(_T("png_files/toolbars/general/tool-read-only.png"))), wxNullBitmap, wxITEM_NORMAL, _("Read-Only"), wxEmptyString, NULL);
    AuiToolBarGeneral->Realize();
    AuiManager->AddPane(AuiToolBarGeneral, wxAuiPaneInfo().Name(_T("General")).ToolbarPane().Caption(_("General")).PinButton().Layer(10).Top().Gripper());
    AuiToolBarPlacement = new wxAuiToolBar(this, ID_AUITOOLBARPLACEMENT, wxPoint(179,134), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarPlacement->AddTool(ID_AUITOOLBARITEMSINGLEICON, _("Single Icon"), wxBitmap(wxImage(_T("png_files/toolbars/placement/tool-single-icon.png"))), wxNullBitmap, wxITEM_NORMAL, _("Single Icon"), wxEmptyString, NULL);
    AuiToolBarPlacement->AddTool(ID_AUITOOLBARITEMSQUAREPLACEMENT, _("Square Placement"), wxBitmap(wxImage(_T("png_files/toolbars/placement/tool-square-placement.png"))), wxNullBitmap, wxITEM_NORMAL, _("Square Placement"), wxEmptyString, NULL);
    AuiToolBarPlacement->AddTool(ID_AUITOOLBARITEMDIAMONDPLACEMENT, _("Diamong Placement"), wxBitmap(wxImage(_T("png_files/toolbars/placement/tool-diamond-placement.png"))), wxNullBitmap, wxITEM_NORMAL, _("Diamond Placement"), wxEmptyString, NULL);
    AuiToolBarPlacement->AddTool(ID_AUITOOLBARITEMRANDOMPLACEMENT, _("Random Placement"), wxBitmap(wxImage(_T("png_files/toolbars/placement/tool-random-placement.png"))), wxNullBitmap, wxITEM_NORMAL, _("Random Placement"), wxEmptyString, NULL);
    AuiToolBarPlacement->AddTool(ID_AUITOOLBARITEMDEFINESYMBOL, _("Define Selection as symbol"), wxBitmap(wxImage(_T("png_files/toolbars/placement/tool-define-selection-as-symbol.png"))), wxNullBitmap, wxITEM_NORMAL, _("Define Selection as Symbol"), wxEmptyString, NULL);
    AuiToolBarPlacement->AddTool(ID_AUITOOLBARITEMSYMBOLLIBRARY, _("Symbol Library"), wxBitmap(wxImage(_T("png_files/toolbars/placement/tool-symbol-library.png"))), wxNullBitmap, wxITEM_NORMAL, _("Symbol Library"), wxEmptyString, NULL);
    AuiToolBarPlacement->Realize();
    AuiManager->AddPane(AuiToolBarPlacement, wxAuiPaneInfo().Name(_T("Placement")).ToolbarPane().Caption(_("Placement")).Layer(10).Position(10).Left().Gripper());
    AuiToolBarLineStyle = new wxAuiToolBar(this, ID_AUITOOLBARLINESTYLE, wxPoint(173,138), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    ChoiceStart = new wxChoice(AuiToolBarLineStyle, ID_CHOICESTART, wxPoint(52,7), wxSize(31,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICESTART"));
    ChoiceBody = new wxChoice(AuiToolBarLineStyle, ID_CHOICEBODY, wxPoint(152,18), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEBODY"));
    ChoiceEnd = new wxChoice(AuiToolBarLineStyle, ID_CHOICEEND, wxPoint(210,15), wxSize(23,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEEND"));
    SpinCtrlThickness = new wxSpinCtrl(AuiToolBarLineStyle, ID_SPINCTRLTHICKNESS, _T("0"), wxPoint(292,10), wxSize(34,25), 0, 0, 100, 0, _T("ID_SPINCTRLTHICKNESS"));
    SpinCtrlThickness->SetValue(_T("0"));
    AuiToolBarLineStyle->AddControl(ChoiceStart, _("Item label"));
    AuiToolBarLineStyle->AddControl(ChoiceBody, _("Item label"));
    AuiToolBarLineStyle->AddControl(ChoiceEnd, _("Item label"));
    AuiToolBarLineStyle->AddControl(SpinCtrlThickness, _("Item label"));
    AuiToolBarLineStyle->Realize();
    AuiManager->AddPane(AuiToolBarLineStyle, wxAuiPaneInfo().Name(_T("LineStyle")).ToolbarPane().Caption(_("LineStyle")).Layer(5).Position(9).Top().Gripper());
    AuiToolBarEdinting = new wxAuiToolBar(this, ID_AUITOOLBAREDITING, wxPoint(162,151), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMSENDBACK, _("Send to back"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-send-to-back.png"))), wxNullBitmap, wxITEM_NORMAL, _("Send to Back"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMSENDBACKWARD, _("Send Backward"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-send-backward.png"))), wxNullBitmap, wxITEM_NORMAL, _("Send Backward"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMSENDFORWARD, _("Bring Forward"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-bring-forward.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMSENDFRONT, _("Send to Front"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-bring-to-front.png"))), wxNullBitmap, wxITEM_NORMAL, _("Send to Front"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddSeparator();
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMPASTE, _("Paste"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-paste.png"))), wxNullBitmap, wxITEM_NORMAL, _("Paste"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMCOPY, _("Copy"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-copy.png"))), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMCUT, _("Cut"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-cut.png"))), wxNullBitmap, wxITEM_NORMAL, _("Cut"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddSeparator();
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMDELETE, _("Delete"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-delete.png"))), wxNullBitmap, wxITEM_NORMAL, _("Delete"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMSCALPEL, _("Scalpel"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-scalpel.png"))), wxNullBitmap, wxITEM_NORMAL, _("Scalpel"), wxEmptyString, NULL);
    AuiToolBarEdinting->AddTool(ID_AUITOOLBARITEMGLUE, _("Glue"), wxBitmap(wxImage(_T("png_files/toolbars/editing/tool-glue.png"))), wxNullBitmap, wxITEM_NORMAL, _("Glue"), wxEmptyString, NULL);
    AuiToolBarEdinting->Realize();
    AuiManager->AddPane(AuiToolBarEdinting, wxAuiPaneInfo().Name(_T("Editing")).ToolbarPane().Caption(_("Editing")).Layer(10).Position(8).Left().Gripper());
    AuiToolBarFractal = new wxAuiToolBar(this, ID_AUITOOLBARFRACTAL, wxPoint(156,162), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarFractal->AddTool(ID_AUITOOLBARITEMFREEHANDFRACTAL, _("FreeHand"), wxBitmap(wxImage(_T("png_files/toolbars/fractal/tool-frac-freehand.png"))), wxNullBitmap, wxITEM_NORMAL, _("FreeHandFractal"), wxEmptyString, NULL);
    AuiToolBarFractal->AddTool(ID_AUITOOLBARITEMLINEFRACTAL, _("Line"), wxBitmap(wxImage(_T("png_files/toolbars/fractal/tool-frac-line.png"))), wxNullBitmap, wxITEM_NORMAL, _("LineFractal"), wxEmptyString, NULL);
    AuiToolBarFractal->AddTool(ID_AUITOOLBARITEMPOLYLINEFRACTAL, _("PolyLine"), wxBitmap(wxImage(_T("png_files/toolbars/fractal/tool-frac-polyline.png"))), wxNullBitmap, wxITEM_NORMAL, _("PolyLineFractal"), wxEmptyString, NULL);
    AuiToolBarFractal->AddTool(ID_AUITOOLBARITEMCURVEFRACTAL, _("Curve"), wxBitmap(wxImage(_T("png_files/toolbars/fractal/tool-frac-curve.png"))), wxNullBitmap, wxITEM_NORMAL, _("CurveFractal"), wxEmptyString, NULL);
    AuiToolBarFractal->AddTool(ID_AUITOOLBARITEMPOLYCURVEFRACTAL, _("PolyCurve"), wxBitmap(wxImage(_T("png_files/toolbars/fractal/tool-frac-polycurve.png"))), wxNullBitmap, wxITEM_NORMAL, _("PolyCurveFractal"), wxEmptyString, NULL);
    AuiToolBarFractal->Realize();
    AuiManager->AddPane(AuiToolBarFractal, wxAuiPaneInfo().Name(_T("Fractal")).ToolbarPane().Caption(_("Pane caption")).PinButton().Layer(5).Position(1).Top().Gripper());
    AuiToolBarDrawing = new wxAuiToolBar(this, ID_AUITOOLBARDRAWING, wxPoint(68,144), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMRECTANGLE, _("Rectangle"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-rectangle.png"))), wxNullBitmap, wxITEM_NORMAL, _("Rectangle"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMCIRCLE, _("Circle"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-circle.png"))), wxNullBitmap, wxITEM_NORMAL, _("Circle"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMPOLYGON, _("Polygon"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-polygon.png"))), wxNullBitmap, wxITEM_NORMAL, _("Polygon"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMARC, _("Arc"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-arc.png"))), wxNullBitmap, wxITEM_NORMAL, _("Arc"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMROSETTECHARTLINES, _("RosetteChartLines"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-rosette-chart-lines.png"))), wxNullBitmap, wxITEM_NORMAL, _("Rosette Chart Lines"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddSeparator();
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMTEXT, _("Text"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-text.png"))), wxNullBitmap, wxITEM_NORMAL, _("Text"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMCURVEDTEXT, _("Curved Text"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-curved-text.png"))), wxNullBitmap, wxITEM_NORMAL, _("Curved Text"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMHYPERLINKPOPUP, _("HyperlinkPopup"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-hyperlink-popup.png"))), wxNullBitmap, wxITEM_NORMAL, _("Hyperlink/Popup"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddSeparator();
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMGROUP, _("Group"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-group.png"))), wxNullBitmap, wxITEM_NORMAL, _("Group"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMUNGROUP, _("Ungroup"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-ungroup.png"))), wxNullBitmap, wxITEM_NORMAL, _("Ungroup"), wxEmptyString, NULL);
    AuiToolBarDrawing->AddTool(ID_AUITOOLBARITEMDECOMPOSE, _("Decompose"), wxBitmap(wxImage(_T("png_files/toolbars/drawing/tool-decompose.png"))), wxNullBitmap, wxITEM_NORMAL, _("Decompose"), wxEmptyString, NULL);
    AuiToolBarDrawing->Realize();
    AuiManager->AddPane(AuiToolBarDrawing, wxAuiPaneInfo().Name(_T("Drawing")).ToolbarPane().Caption(_("Drawing")).PinButton().Layer(5).Top().Gripper());
    AuiNotebookWorkspace = new wxAuiNotebook(this, ID_AUINOTEBOOKWORKSPACE, wxPoint(446,171), wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
    ScrolledWindowMap1 = new wxScrolledWindow(AuiNotebookWorkspace, ID_SCROLLEDWINDOWMAP1, wxPoint(65,195), wxDefaultSize, wxHSCROLL|wxVSCROLL, _T("ID_SCROLLEDWINDOWMAP1"));
    AuiNotebookWorkspace->AddPage(ScrolledWindowMap1, _("Map 1"), true);
    AuiManager->AddPane(AuiNotebookWorkspace, wxAuiPaneInfo().Name(_T("Workspace")).Caption(_("Workspace")).CaptionVisible(false).CloseButton(false).Center());
    AuiToolBarFractalSettings = new wxAuiToolBar(this, ID_AUITOOLBARFRACTALSETTINGS, wxPoint(58,233), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    StaticBoxFractalSettings = new wxStaticBox(AuiToolBarFractalSettings, ID_STATICBOXFRACTALSETTINGS, _("Fractal Settings"), wxPoint(23,5), wxDefaultSize, 0, _T("ID_STATICBOXFRACTALSETTINGS"));
    StaticBitmapRoughness = new wxStaticBitmap(AuiToolBarFractalSettings, ID_STATICBITMAPROUGHNESS, wxBitmap(wxImage(_T("png_files/toolbars/fractals_settings/roughness.png"))), wxPoint(376,16), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAPROUGHNESS"));
    SliderRoughness = new wxSlider(AuiToolBarFractalSettings, ID_SLIDERROUGHNESS, 0, 0, 10, wxPoint(390,9), wxSize(70,17), 0, wxDefaultValidator, _T("ID_SLIDERROUGHNESS"));
    StaticBitmapAcorn = new wxStaticBitmap(AuiToolBarFractalSettings, ID_STATICBITMAPACORN, wxBitmap(wxImage(_T("png_files/toolbars/fractals_settings/acorn-main.png"))), wxPoint(311,10), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAPACORN"));
    SpinCtrlSeed = new wxSpinCtrl(AuiToolBarFractalSettings, ID_SPINCTRLSEED, _T("0"), wxPoint(224,10), wxSize(44,25), 0, 0, 100, 0, _T("ID_SPINCTRLSEED"));
    SpinCtrlSeed->SetValue(_T("0"));
    AuiToolBarFractalSettings->AddControl(StaticBoxFractalSettings, _("Fractal Settings"));
    AuiToolBarFractalSettings->AddControl(StaticBitmapRoughness, _("Roughness"));
    AuiToolBarFractalSettings->AddControl(SliderRoughness, _("Roughness"));
    AuiToolBarFractalSettings->AddControl(StaticBitmapAcorn, _("Acorn"));
    AuiToolBarFractalSettings->AddControl(SpinCtrlSeed, _("Seed"));
    AuiToolBarFractalSettings->Realize();
    AuiManager->AddPane(AuiToolBarFractalSettings, wxAuiPaneInfo().Name(_T("Fractal Settings")).ToolbarPane().Caption(_("Fractal Settings")).Layer(10).Right().Gripper());
    AuiToolBarGrapPaper = new wxAuiToolBar(this, ID_AUITOOLBARGRAPHPAPER, wxPoint(174,260), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    StaticBoxGraphPaper = new wxStaticBox(AuiToolBarGrapPaper, ID_STATICBOXGRAPHPAPER, _("Graph Paper"), wxPoint(29,7), wxDefaultSize, 0, _T("ID_STATICBOXGRAPHPAPER"));
    TextCtrlGridSize = new wxTextCtrl(AuiToolBarGrapPaper, ID_TEXTCTRLGRIDSIZE, wxEmptyString, wxPoint(222,16), wxSize(49,25), 0, wxDefaultValidator, _T("ID_TEXTCTRLGRIDSIZE"));
    StaticTextDimension = new wxStaticText(AuiToolBarGrapPaper, ID_STATICTEXTDIMENSION, _("squares/cm"), wxPoint(323,13), wxDefaultSize, 0, _T("ID_STATICTEXTDIMENSION"));
    StaticBitmapGridSize = new wxStaticBitmap(AuiToolBarGrapPaper, ID_STATICBITMAPGRIDSIZE, wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/gridsize-image.png"))), wxPoint(367,12), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAPGRIDSIZE"));
    SliderGridSize = new wxSlider(AuiToolBarGrapPaper, ID_SLIDERGRIDSIZE, 0, 0, 100, wxPoint(377,20), wxSize(86,17), 0, wxDefaultValidator, _T("ID_SLIDERGRIDSIZE"));
    StaticBitmapBoldGrid = new wxStaticBitmap(AuiToolBarGrapPaper, ID_STATICBITMAPBOLDGRID, wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/boldgrid-image.png"))), wxPoint(368,16), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAPBOLDGRID"));
    SpinCtrlSecondaryGrid = new wxSpinCtrl(AuiToolBarGrapPaper, ID_SPINCTRLSECONDARYGRID, _T("0"), wxPoint(365,13), wxSize(47,25), 0, 0, 100, 0, _T("ID_SPINCTRLSECONDARYGRID"));
    SpinCtrlSecondaryGrid->SetValue(_T("0"));
    ChoicePrimGridStyle = new wxChoice(AuiToolBarGrapPaper, ID_CHOICEPRIMGRIDSTYLE, wxPoint(535,16), wxSize(45,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEPRIMGRIDSTYLE"));
    ChoiceSecGridStyle = new wxChoice(AuiToolBarGrapPaper, ID_CHOICESECGRIDSTYLE, wxPoint(620,14), wxSize(34,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICESECGRIDSTYLE"));
    AuiToolBarGrapPaper->AddControl(StaticBoxGraphPaper, _("Graph Paper"));
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMNOGRID, _("No Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-none.png"))), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMSQUAREGRID, _("Square Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-square.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMHEXGRID, _("Hex Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-hex.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMRHEXGRID, _("Rotated Hex Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-rhex.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMTRIANGLEGRID, _("Triangle Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-triangle.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMDIAMONDGRID, _("Diamond Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-diamond.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMHDIAMONDGRID, _("Half Diamond Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-hdiamond.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddTool(ID_AUITOOLBARITEMPOLARGRID, _("Polar Grid"), wxBitmap(wxImage(_T("png_files/toolbars/graph_paper/graph-circle.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);
    AuiToolBarGrapPaper->AddControl(TextCtrlGridSize, _("Grid Size"));
    AuiToolBarGrapPaper->AddControl(StaticTextDimension, _("Squares/cm"));
    AuiToolBarGrapPaper->AddControl(StaticBitmapGridSize, _("Grid Size bmp"));
    AuiToolBarGrapPaper->AddControl(SliderGridSize, _("Grid Size"));
    AuiToolBarGrapPaper->AddControl(StaticBitmapBoldGrid, _("BoldGrid"));
    AuiToolBarGrapPaper->AddControl(SpinCtrlSecondaryGrid, _("Secondary Grid Size"));
    AuiToolBarGrapPaper->AddControl(ChoicePrimGridStyle, _("Primary Grid Style"));
    AuiToolBarGrapPaper->AddControl(ChoiceSecGridStyle, _("Secondary Grid Style"));
    AuiToolBarGrapPaper->Realize();
    AuiManager->AddPane(AuiToolBarGrapPaper, wxAuiPaneInfo().Name(_T("Graph Paper")).ToolbarPane().Caption(_("Graph Paper")).Layer(10).Right().Gripper());
    AuiToolBarIconSettings = new wxAuiToolBar(this, ID_AUITOOLBARICONSETTINGS, wxPoint(174,260), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    StaticBoxIconSettings = new wxStaticBox(AuiToolBarIconSettings, ID_STATICBOXICONSETTINGS, _("Icon Settings"), wxPoint(33,7), wxDefaultSize, 0, _T("ID_STATICBOXICONSETTINGS"));
    StaticBitmapIconSize = new wxStaticBitmap(AuiToolBarIconSettings, ID_STATICBITMAPICONSIZE, wxBitmap(wxImage(_T("png_files/toolbars/icon_settings/sizeimage.png"))), wxPoint(296,5), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAPICONSIZE"));
    SliderIconSize = new wxSlider(AuiToolBarIconSettings, ID_SLIDERICONSIZE, 0, 0, 10, wxPoint(317,14), wxSize(74,17), wxSL_AUTOTICKS, wxDefaultValidator, _T("ID_SLIDERICONSIZE"));
    StaticBitmapDensity = new wxStaticBitmap(AuiToolBarIconSettings, ID_STATICBITMAPDENSITY, wxBitmap(wxImage(_T("png_files/toolbars/icon_settings/densityimage.png"))), wxPoint(352,13), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAPDENSITY"));
    SliderIconSpread = new wxSlider(AuiToolBarIconSettings, ID_SLIDERICONSPREAD, 0, 0, 10, wxPoint(257,15), wxSize(68,17), 0, wxDefaultValidator, _T("ID_SLIDERICONSPREAD"));
    AuiToolBarIconSettings->AddControl(StaticBoxIconSettings, _("Icon Settings"));
    AuiToolBarIconSettings->AddControl(StaticBitmapIconSize, _("Size Image"));
    AuiToolBarIconSettings->AddControl(SliderIconSize, _("Icon Size"));
    AuiToolBarIconSettings->AddControl(StaticBitmapDensity, _("Desity Images"));
    AuiToolBarIconSettings->AddControl(SliderIconSpread, _("Icon Spread"));
    AuiToolBarIconSettings->Realize();
    AuiManager->AddPane(AuiToolBarIconSettings, wxAuiPaneInfo().Name(_T("Icon Settings")).ToolbarPane().Caption(_("Icon Settings")).Layer(10).Right().Gripper());
    AuiToolBarOverlay = new wxAuiToolBar(this, ID_AUITOOLBAROVERLAY, wxPoint(174,260), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    ComboBoxActive = new wxComboBox(AuiToolBarOverlay, ID_COMBOBOXACTIVE, wxEmptyString, wxPoint(61,8), wxSize(79,25), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOXACTIVE"));
    CheckListBoxList = new wxCheckListBox(AuiToolBarOverlay, ID_CHECKLISTBOXLIST, wxPoint(11,40), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOXLIST"));
    AuiToolBarOverlay->AddControl(ComboBoxActive, _("Item label"));
    AuiToolBarOverlay->AddControl(CheckListBoxList, _("Item label"));
    AuiToolBarOverlay->Realize();
    AuiManager->AddPane(AuiToolBarOverlay, wxAuiPaneInfo().Name(_T("Overlay")).ToolbarPane().Caption(_("Overlay")).Layer(10).Right().Gripper());
    AuiToolBarPushPins = new wxAuiToolBar(this, ID_AUITOOLBARPUSHPINS, wxPoint(174,260), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    CheckListBoxPushPins = new wxCheckListBox(AuiToolBarPushPins, ID_CHECKLISTBOXPUSHPINS, wxPoint(49,12), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOXPUSHPINS"));
    AuiToolBarPushPins->AddControl(CheckListBoxPushPins, _("Push Pins"));
    AuiToolBarPushPins->Realize();
    AuiManager->AddPane(AuiToolBarPushPins, wxAuiPaneInfo().Name(_T("Push-Pins")).ToolbarPane().Caption(_("Push_Pins")).Layer(10).Right().Gripper());
    AuiManager->Update();
    MenuBar = new wxMenuBar();
    MenuFile = new wxMenu();
    MenuItemNew = new wxMenuItem(MenuFile, idMenuNew, _("&New\tCtrl-n"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemNew);
    MenuItemOpen = new wxMenuItem(MenuFile, idMenuOpen, _("&Open\tCtrl-o"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemOpen);
    MenuItemReopen = new wxMenuItem(MenuFile, idMenuReopen, _("&Reopen\tCtrl-Shift-o"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemReopen);
    MenuFile->AppendSeparator();
    MenuItemSave = new wxMenuItem(MenuFile, idMenuSave, _("&Save\tCtrl-s"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemSave);
    MenuItemSaveAs = new wxMenuItem(MenuFile, idMenuSaveAs, _("Save &As...\tCtrl-Shift-s"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemSaveAs);
    MenuItemInsert = new wxMenuItem(MenuFile, idMenuInsert, _("&Insert...\tCtrl-j"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemInsert);
    MenuFile->AppendSeparator();
    MenuItemPrint = new wxMenuItem(MenuFile, idMenuPrint, _("&Print...\tCtrl-p"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemPrint);
    MenuItemPrintSetup = new wxMenuItem(MenuFile, idMenuPrintSetup, _("P&rint Setup...\tCtrl-Shift-p"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemPrintSetup);
    MenuFile->AppendSeparator();
    MenuItemProperties = new wxMenuItem(MenuFile, idMenuProperties, _("Proper&ties\tAlt-Enter"), wxEmptyString, wxITEM_NORMAL);
    MenuFile->Append(MenuItemProperties);
    MenuItemExit = new wxMenuItem(MenuFile, idMenuQuit, _("&Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemExit);
    MenuBar->Append(MenuFile, _("&File"));
    MenuEdit = new wxMenu();
    MenuItemUndo = new wxMenuItem(MenuEdit, idMenuUndo, _("&Undo\tCtrl-z"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemUndo);
    MenuItemUndo->Enable(false);
    MenuItemRedo = new wxMenuItem(MenuEdit, idMenuRedo, _("&Redo\tCtrl-y"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemRedo);
    MenuItemRedo->Enable(false);
    MenuEdit->AppendSeparator();
    MenuItemCut = new wxMenuItem(MenuEdit, idMenuCut, _("Cu&t\tCtrl-x"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemCut);
    MenuItemCopy = new wxMenuItem(MenuEdit, idMenuCopy, _("&Copy\tCtrl-c"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemCopy);
    MenuItemPaste = new wxMenuItem(MenuEdit, idMenuPaste, _("&Paste\tCtrl-v"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemPaste);
    MenuItemDelete = new wxMenuItem(MenuEdit, idMenuDelete, _("&Delete\tCtrl-d"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemDelete);
    MenuEdit->AppendSeparator();
    MenuItemSelectAll = new wxMenuItem(MenuEdit, idMenuSelectAll, _("Se&lect All\tCtrl-a"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemSelectAll);
    MenuItemSelectNone = new wxMenuItem(MenuEdit, idMenuSelectNone, _("Select &None"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemSelectNone);
    MenuEdit->AppendSeparator();
    MenuItemSelTool = new wxMenuItem(MenuEdit, idMenuUseSelectionTool, _("Use Selection/Arro&w Tool\tCtrl-w"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemSelTool);
    MenuItemPanning = new wxMenuItem(MenuEdit, idMenuUsePanningTool, _("Use &Panning Tool\tCtrl-e"), wxEmptyString, wxITEM_NORMAL);
    MenuEdit->Append(MenuItemPanning);
    MenuBar->Append(MenuEdit, _("&Edit"));
    MenuView = new wxMenu();
    MenuItemZin = new wxMenuItem(MenuView, idMenuZoomIn, _("Zoom &In\tCtrl-+"), wxEmptyString, wxITEM_NORMAL);
    MenuView->Append(MenuItemZin);
    MenuItemZout = new wxMenuItem(MenuView, idMenuZoomOut, _("Zoom &Out\tCtrl--"), wxEmptyString, wxITEM_NORMAL);
    MenuView->Append(MenuItemZout);
    MenuZoom = new wxMenu();
    MenuItemFit = new wxMenuItem(MenuZoom, idMenuFit, _("Fit"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemFit);
    MenuItemZ10 = new wxMenuItem(MenuZoom, idMenu10, _("10%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ10);
    MenuItemZ25 = new wxMenuItem(MenuZoom, idMenu25, _("25%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ25);
    MenuItemZ50 = new wxMenuItem(MenuZoom, idMenu50, _("50%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ50);
    MenuItemZ75 = new wxMenuItem(MenuZoom, idMenu75, _("75%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ75);
    MenuItemZ100 = new wxMenuItem(MenuZoom, idMenu100, _("100%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ100);
    MenuItemZ150 = new wxMenuItem(MenuZoom, idMenu150, _("150%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ150);
    MenuItemZ200 = new wxMenuItem(MenuZoom, idMenu200, _("200%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ200);
    MenuItemZ300 = new wxMenuItem(MenuZoom, idMenu300, _("300%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ300);
    MenuItemZ400 = new wxMenuItem(MenuZoom, idMenu400, _("400%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ400);
    MenuItemZ500 = new wxMenuItem(MenuZoom, idMenu500, _("500%"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZ500);
    MenuItemZCustom = new wxMenuItem(MenuZoom, idMenuCustomZoom, _("Custom"), wxEmptyString, wxITEM_NORMAL);
    MenuZoom->Append(MenuItemZCustom);
    MenuView->Append(ID_MENUITEMZOOM, _("Zoom"), MenuZoom, wxEmptyString);
    MenuItemShowAll = new wxMenuItem(MenuView, idMenuShowAll, _("Show &All Objects"), wxEmptyString, wxITEM_NORMAL);
    MenuView->Append(MenuItemShowAll);
    MenuItemReadOnly = new wxMenuItem(MenuView, ID_MENUITEMREADONLY, _("&Read Only"), wxEmptyString, wxITEM_NORMAL);
    MenuView->Append(MenuItemReadOnly);
    MenuView->AppendSeparator();
    MenuItemSaveView = new wxMenuItem(MenuView, ID_MENUITEMSAVEVIEW, _("&Save Current View..."), wxEmptyString, wxITEM_NORMAL);
    MenuView->Append(MenuItemSaveView);
    MenuItemDeleteView = new wxMenuItem(MenuView, ID_MENUITEMDELETEVIEW, _("&Delete View..."), wxEmptyString, wxITEM_NORMAL);
    MenuView->Append(MenuItemDeleteView);
    MenuItemDeleteView->Enable(false);
    MenuBar->Append(MenuView, _("&View"));
    MenuTransform = new wxMenu();
    MenuItem1 = new wxMenuItem(MenuTransform, ID_MENUITEM1, _("Move"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(MenuTransform, ID_MENUITEM2, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(MenuTransform, ID_MENUITEM3, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(MenuTransform, ID_MENUITEM4, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(MenuTransform, ID_MENUITEM5, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem6);
    MenuTransform->AppendSeparator();
    MenuItem7 = new wxMenuItem(MenuTransform, ID_MENUITEM6, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(MenuTransform, ID_MENUITEM7, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem8);
    MenuTransform->AppendSeparator();
    MenuItem9 = new wxMenuItem(MenuTransform, ID_MENUITEM8, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem9);
    MenuItem10 = new wxMenu();
    MenuItem11 = new wxMenuItem(MenuItem10, ID_MENUITEM10, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->Append(MenuItem11);
    MenuItem12 = new wxMenuItem(MenuItem10, ID_MENUITEM11, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(MenuItem10, ID_MENUITEM12, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->Append(MenuItem13);
    MenuItem14 = new wxMenuItem(MenuItem10, ID_MENUITEM13, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->Append(MenuItem14);
    MenuItem10->AppendSeparator();
    MenuItem15 = new wxMenuItem(MenuItem10, ID_MENUITEM14, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->Append(MenuItem15);
    MenuItem16 = new wxMenuItem(MenuItem10, ID_MENUITEM15, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->Append(MenuItem16);
    MenuTransform->Append(ID_MENUITEM9, _("New Menu"), MenuItem10, wxEmptyString);
    MenuTransform->AppendSeparator();
    MenuItem17 = new wxMenu();
    MenuItem18 = new wxMenuItem(MenuItem17, ID_MENUITEM17, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem17->Append(MenuItem18);
    MenuItem19 = new wxMenuItem(MenuItem17, ID_MENUITEM18, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem17->Append(MenuItem19);
    MenuItem20 = new wxMenuItem(MenuItem17, ID_MENUITEM19, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuItem17->Append(MenuItem20);
    MenuTransform->Append(ID_MENUITEM16, _("New Menu"), MenuItem17, wxEmptyString);
    MenuTransform->AppendSeparator();
    MenuItem21 = new wxMenuItem(MenuTransform, ID_MENUITEM20, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem21);
    MenuItem22 = new wxMenuItem(MenuTransform, ID_MENUITEM21, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem22);
    MenuItem23 = new wxMenuItem(MenuTransform, ID_MENUITEM22, _("New Menu"), wxEmptyString, wxITEM_NORMAL);
    MenuTransform->Append(MenuItem23);
    MenuBar->Append(MenuTransform, _("&Transform"));
    MenuDrawing = new wxMenu();
    MenuBar->Append(MenuDrawing, _("&Drawing"));
    MenuToolbar = new wxMenu();
    MenuBar->Append(MenuToolbar, _("&Toolbar"));
    MenuOptions = new wxMenu();
    MenuBar->Append(MenuOptions, _("&Options"));
    MenuWizards = new wxMenu();
    MenuBar->Append(MenuWizards, _("&Wizards"));
    MenuHelp = new wxMenu();
    MenuItem2 = new wxMenuItem(MenuHelp, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuHelp->Append(MenuItem2);
    MenuBar->Append(MenuHelp, _("&Help"));
    SetMenuBar(MenuBar);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&autorealm_GUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&autorealm_GUIFrame::OnAbout);
    //*)
}

autorealm_GUIFrame::~autorealm_GUIFrame()
{
    //(*Destroy(autorealm_GUIFrame)
    //*)
}

void autorealm_GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void autorealm_GUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
