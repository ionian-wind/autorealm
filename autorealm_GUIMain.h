/***************************************************************
 * Name:      autorealm_GUIMain.h
 * Purpose:   Defines Application Frame
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

#ifndef AUTOREALM_GUIMAIN_H
#define AUTOREALM_GUIMAIN_H

//(*Headers(autorealm_GUIFrame)
#include <wx/checklst.h>
#include <wx/spinctrl.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/scrolwin.h>
#include <wx/slider.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/aui/aui.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/listbox.h>
//*)

class autorealm_GUIFrame: public wxFrame
{
    public:

        autorealm_GUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~autorealm_GUIFrame();

    private:

        //(*Handlers(autorealm_GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAuiToolBarItemTranslateColorClick(wxCommandEvent& event);
        void OnScrolledWindow1Paint(wxPaintEvent& event);
        //*)

        //(*Identifiers(autorealm_GUIFrame)
        static const long ID_AUITOOLBARITEMFREEHAND;
        static const long ID_AUITOOLBARITEMLINE;
        static const long ID_AUITOOLBARITEMPOLYLINE;
        static const long ID_AUITOOLBARITEMCURVE;
        static const long ID_AUITOOLBARITEMPOLYCURVE;
        static const long ID_AUITOOLBARSHAPE;
        static const long ID_AUITOOLBARITEMALIGN;
        static const long ID_AUITOOLBARITEMFLIP;
        static const long ID_AUITOOLBARITEMSKEW;
        static const long ID_AUITOOLBARITEMROTATE;
        static const long ID_AUITOOLBARITEMSCALE;
        static const long ID_AUITOOLBARITEMMOVE;
        static const long ID_AUITOOLBARITEMROT90;
        static const long ID_AUITOOLBARITEMROT45;
        static const long ID_AUITOOLBARITEMARRAY;
        static const long ID_AUITOOLBARITEMORDER;
        static const long ID_AUITOOLBARTRANSFORM;
        static const long ID_AUITOOLBARITEMTOGGLEOVERLAY;
        static const long ID_AUITOOLBARITEMGRID;
        static const long ID_AUITOOLBARITEMGRAVITY;
        static const long ID_AUITOOLBARITEMGRIDSNAP;
        static const long ID_AUITOOLBARITEMLINEGRAVITY;
        static const long ID_AUITOOLBARITEMROTATESNAP;
        static const long ID_AUITOOLBARGRIDSETTINGS;
        static const long ID_AUITOOLBARITEMMAINCOLOR;
        static const long ID_AUITOOLBARITEMFILLCOLOR;
        static const long ID_AUITOOLBARITEMFILLPATTERN;
        static const long ID_AUITOOLBARITEMTEXTOUTLINECOLOR;
        static const long ID_AUITOOLBARITEMBACKGROUNDCOLOR;
        static const long ID_AUITOOLBARITEMGRIDCOLOR;
        static const long ID_AUITOOLBARITEMSHOWCOLORMANAGER;
        static const long ID_AUITOOLBARITEMTRANSLATECOLOR;
        static const long ID_AUITOOLBARITEMINVERSETRANSLATECOLOR;
        static const long ID_AUITOOLBARCOLOR;
        static const long ID_AUITOOLBARITEMZOOM;
        static const long ID_COMBOBOXZOOM;
        static const long ID_AUITOOLBARZOOM;
        static const long ID_LISTBOXNAMES;
        static const long ID_LISTVIEWCONTENT;
        static const long ID_AUITOOLBARPAGES;
        static const long ID_STATICTEXTWIDTH;
        static const long ID_SPINCTRLWIDTH;
        static const long ID_STATICTEXTHEIGHT;
        static const long ID_SPINCTRLHEIGHT;
        static const long ID_CHECKBOXASPECT;
        static const long ID_AUITOOLBARSIZE;
        static const long ID_AUITOOLBARITEMSELECT;
        static const long ID_AUITOOLBARITEMOPEN;
        static const long ID_AUITOOLBARITEMSAVE;
        static const long ID_AUITOOLBARITEMPAN;
        static const long ID_AUITOOLBARITEMRULER;
        static const long ID_AUITOOLBARITEMMEASUREMENTSTRING;
        static const long ID_AUITOOLBARITEMREPAINT;
        static const long ID_AUITOOLBARITEMUNDO;
        static const long ID_AUITOOLBARITEMREDO;
        static const long ID_AUITOOLBARITEMREADONLY;
        static const long ID_AUITOOLBAR9GENERAL;
        static const long ID_AUITOOLBARITEMSINGLEICON;
        static const long ID_AUITOOLBARITEMSQUAREPLACEMENT;
        static const long ID_AUITOOLBARITEMDIAMONDPLACEMENT;
        static const long ID_AUITOOLBARITEMRANDOMPLACEMENT;
        static const long ID_AUITOOLBARITEMDEFINESYMBOL;
        static const long ID_AUITOOLBARITEMSYMBOLLIBRARY;
        static const long ID_AUITOOLBARPLACEMENT;
        static const long ID_CHOICESTART;
        static const long ID_CHOICEBODY;
        static const long ID_CHOICEEND;
        static const long ID_SPINCTRLTHICKNESS;
        static const long ID_AUITOOLBARLINESTYLE;
        static const long ID_AUITOOLBARITEMSENDBACK;
        static const long ID_AUITOOLBARITEMSENDBACKWARD;
        static const long ID_AUITOOLBARITEMSENDFORWARD;
        static const long ID_AUITOOLBARITEMSENDFRONT;
        static const long ID_AUITOOLBARITEMPASTE;
        static const long ID_AUITOOLBARITEMCOPY;
        static const long ID_AUITOOLBARITEMCUT;
        static const long ID_AUITOOLBARITEMDELETE;
        static const long ID_AUITOOLBARITEMSCALPEL;
        static const long ID_AUITOOLBARITEMGLUE;
        static const long ID_AUITOOLBAREDITING;
        static const long ID_AUITOOLBARITEMFREEHANDFRACTAL;
        static const long ID_AUITOOLBARITEMLINEFRACTAL;
        static const long ID_AUITOOLBARITEMPOLYLINEFRACTAL;
        static const long ID_AUITOOLBARITEMCURVEFRACTAL;
        static const long ID_AUITOOLBARITEMPOLYCURVEFRACTAL;
        static const long ID_AUITOOLBARFRACTAL;
        static const long ID_AUITOOLBARITEMRECTANGLE;
        static const long ID_AUITOOLBARITEMCIRCLE;
        static const long ID_AUITOOLBARITEMPOLYGON;
        static const long ID_AUITOOLBARITEMARC;
        static const long ID_AUITOOLBARITEMROSETTECHARTLINES;
        static const long ID_AUITOOLBARITEMTEXT;
        static const long ID_AUITOOLBARITEMCURVEDTEXT;
        static const long ID_AUITOOLBARITEMHYPERLINKPOPUP;
        static const long ID_AUITOOLBARITEMGROUP;
        static const long ID_AUITOOLBARITEMUNGROUP;
        static const long ID_AUITOOLBARITEMDECOMPOSE;
        static const long ID_AUITOOLBARDRAWING;
        static const long ID_SCROLLEDWINDOWMAP1;
        static const long ID_AUINOTEBOOKWORKSPACE;
        static const long ID_STATICBOXFRACTALSETTINGS;
        static const long ID_STATICBITMAPROUGHNESS;
        static const long ID_SLIDERROUGHNESS;
        static const long ID_STATICBITMAPACORN;
        static const long ID_SPINCTRLSEED;
        static const long ID_AUITOOLBARFRACTALSETTINGS;
        static const long ID_STATICBOXGRAPHPAPER;
        static const long ID_AUITOOLBARITEMNOGRID;
        static const long ID_AUITOOLBARITEMSQUAREGRID;
        static const long ID_AUITOOLBARITEMHEXGRID;
        static const long ID_AUITOOLBARITEMRHEXGRID;
        static const long ID_AUITOOLBARITEMTRIANGLEGRID;
        static const long ID_AUITOOLBARITEMDIAMONDGRID;
        static const long ID_AUITOOLBARITEMHDIAMONDGRID;
        static const long ID_AUITOOLBARITEMPOLARGRID;
        static const long ID_TEXTCTRLGRIDSIZE;
        static const long ID_STATICTEXTDIMENSION;
        static const long ID_STATICBITMAPGRIDSIZE;
        static const long ID_SLIDERGRIDSIZE;
        static const long ID_STATICBITMAPBOLDGRID;
        static const long ID_SPINCTRLSECONDARYGRID;
        static const long ID_CHOICEPRIMGRIDSTYLE;
        static const long ID_CHOICESECGRIDSTYLE;
        static const long ID_AUITOOLBARGRAPHPAPER;
        static const long ID_STATICBOXICONSETTINGS;
        static const long ID_STATICBITMAPICONSIZE;
        static const long ID_SLIDERICONSIZE;
        static const long ID_STATICBITMAPDENSITY;
        static const long ID_SLIDERICONSPREAD;
        static const long ID_AUITOOLBARICONSETTINGS;
        static const long ID_COMBOBOXACTIVE;
        static const long ID_CHECKLISTBOXLIST;
        static const long ID_AUITOOLBAROVERLAY;
        static const long ID_CHECKLISTBOXPUSHPINS;
        static const long ID_AUITOOLBARPUSHPINS;
        static const long idMenuNew;
        static const long idMenuOpen;
        static const long idMenuReopen;
        static const long idMenuSave;
        static const long idMenuSaveAs;
        static const long idMenuInsert;
        static const long idMenuPrint;
        static const long idMenuPrintSetup;
        static const long idMenuProperties;
        static const long idMenuQuit;
        static const long idMenuUndo;
        static const long idMenuRedo;
        static const long idMenuCut;
        static const long idMenuCopy;
        static const long idMenuPaste;
        static const long idMenuDelete;
        static const long idMenuSelectAll;
        static const long idMenuSelectNone;
        static const long idMenuUseSelectionTool;
        static const long idMenuUsePanningTool;
        static const long idMenuZoomIn;
        static const long idMenuZoomOut;
        static const long idMenuFit;
        static const long idMenu10;
        static const long idMenu25;
        static const long idMenu50;
        static const long idMenu75;
        static const long idMenu100;
        static const long idMenu150;
        static const long idMenu200;
        static const long idMenu300;
        static const long idMenu400;
        static const long idMenu500;
        static const long idMenuCustomZoom;
        static const long ID_MENUITEMZOOM;
        static const long idMenuShowAll;
        static const long ID_MENUITEMREADONLY;
        static const long ID_MENUITEMSAVEVIEW;
        static const long ID_MENUITEMDELETEVIEW;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM13;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM15;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM17;
        static const long ID_MENUITEM18;
        static const long ID_MENUITEM19;
        static const long ID_MENUITEM16;
        static const long ID_MENUITEM20;
        static const long ID_MENUITEM21;
        static const long ID_MENUITEM22;
        static const long idMenuAbout;
        //*)

        //(*Declarations(autorealm_GUIFrame)
        wxMenuItem* MenuItem23;
        wxChoice* ChoiceEnd;
        wxAuiToolBar* AuiToolBarZoom;
        wxMenuItem* MenuItemSelectAll;
        wxMenu* MenuItem10;
        wxMenuItem* MenuItemZ25;
        wxMenuItem* MenuItemSaveAs;
        wxMenuItem* MenuItem1;
        wxStaticBitmap* StaticBitmapBoldGrid;
        wxMenuItem* MenuItemPaste;
        wxMenuItem* MenuItemUndo;
        wxMenuItem* MenuItemPrint;
        wxStaticText* StaticTextWidth;
        wxStaticText* StaticTextDimension;
        wxMenuItem* MenuItem16;
        wxAuiToolBar* AuiToolBarSize;
        wxMenuItem* MenuItemZ10;
        wxMenu* MenuToolbar;
        wxMenuItem* MenuItem12;
        wxSpinCtrl* SpinCtrlSeed;
        wxAuiToolBar* AuiToolBarLineStyle;
        wxMenu* MenuOptions;
        wxMenuItem* MenuItemZCustom;
        wxComboBox* ComboBoxActive;
        wxSpinCtrl* SpinCtrlSecondaryGrid;
        wxMenuItem* MenuItemZin;
        wxAuiToolBar* AuiToolBarColor;
        wxAuiToolBar* AuiToolBarFractal;
        wxMenuItem* MenuItem19;
        wxMenuItem* MenuItemFit;
        wxMenuItem* MenuItemSave;
        wxSpinCtrl* SpinCtrlWidth;
        wxMenuItem* MenuItem20;
        wxAuiToolBar* AuiToolBarShape;
        wxMenuItem* MenuItemDeleteView;
        wxChoice* ChoicePrimGridStyle;
        wxStaticBitmap* StaticBitmapIconSize;
        wxMenuItem* MenuItemProperties;
        wxMenuItem* MenuItemInsert;
        wxSlider* SliderIconSize;
        wxAuiToolBar* AuiToolBarIconSettings;
        wxAuiToolBar* AuiToolBarDrawing;
        wxChoice* ChoiceStart;
        wxAuiToolBar* AuiToolBarPages;
        wxMenuItem* MenuItem15;
        wxSlider* SliderRoughness;
        wxMenuItem* MenuItemReopen;
        wxListBox* ListBoxNames;
        wxCheckBox* CheckBoxAspect;
        wxAuiToolBar* AuiToolBarEdinting;
        wxMenuItem* MenuItem21;
        wxMenu* MenuWizards;
        wxMenuItem* MenuItemSaveView;
        wxMenuItem* MenuItemShowAll;
        wxMenu* MenuZoom;
        wxStaticBitmap* StaticBitmapDensity;
        wxCheckListBox* CheckListBoxList;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItemPanning;
        wxMenuItem* MenuItemZ75;
        wxMenuItem* MenuItem9;
        wxMenuItem* MenuItemZ400;
        wxMenuItem* MenuItemDelete;
        wxMenuItem* MenuItemNew;
        wxMenuItem* MenuItemZ500;
        wxAuiToolBar* AuiToolBarTransform;
        wxMenuItem* MenuItemZ200;
        wxStaticBitmap* StaticBitmapAcorn;
        wxMenuItem* MenuItemCut;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItemPrintSetup;
        wxChoice* ChoiceBody;
        wxAuiNotebook* AuiNotebookWorkspace;
        wxAuiToolBar* AuiToolBarGridSettings;
        wxMenuItem* MenuItemZout;
        wxAuiToolBar* AuiToolBarFractalSettings;
        wxMenuItem* MenuItem22;
        wxMenuItem* MenuItemSelectNone;
        wxSpinCtrl* SpinCtrlHeight;
        wxMenuItem* MenuItem5;
        wxMenu* MenuView;
        wxAuiToolBar* AuiToolBarOverlay;
        wxListView* ListViewContent;
        wxMenu* MenuDrawing;
        wxMenu* MenuTransform;
        wxMenuItem* MenuItemReadOnly;
        wxScrolledWindow* ScrolledWindowMap1;
        wxMenuItem* MenuItemZ100;
        wxMenuItem* MenuItemZ50;
        wxMenuItem* MenuItemRedo;
        wxSlider* SliderGridSize;
        wxMenu* MenuItem17;
        wxStaticBox* StaticBoxIconSettings;
        wxAuiToolBar* AuiToolBarGrapPaper;
        wxStaticBitmap* StaticBitmapGridSize;
        wxMenuItem* MenuItemSelTool;
        wxComboBox* ComboBoxZoom;
        wxMenuItem* MenuItem18;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem4;
        wxAuiManager* AuiManager;
        wxMenuItem* MenuItem13;
        wxSlider* SliderIconSpread;
        wxStaticBox* StaticBoxFractalSettings;
        wxMenu* MenuEdit;
        wxAuiToolBar* AuiToolBarPushPins;
        wxMenuItem* MenuItemOpen;
        wxChoice* ChoiceSecGridStyle;
        wxMenuItem* MenuItemZ150;
        wxMenuItem* MenuItemZ300;
        wxStaticText* StaticTextHeight;
        wxSpinCtrl* SpinCtrlThickness;
        wxMenuItem* MenuItemCopy;
        wxStaticBox* StaticBoxGraphPaper;
        wxAuiToolBar* AuiToolBarGeneral;
        wxTextCtrl* TextCtrlGridSize;
        wxStaticBitmap* StaticBitmapRoughness;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem14;
        wxAuiToolBar* AuiToolBarPlacement;
        wxCheckListBox* CheckListBoxPushPins;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AUTOREALM_GUIMAIN_H
