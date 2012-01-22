#ifndef CUSTOMGLPANE_H
#define CUSTOMGLPANE_H

//#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "form.h"

class CustomGLPane: public wxGLCanvas
{
public:
    CustomGLPane(wxFrame* parent, int* args);
    virtual ~CustomGLPane();

    void resized(wxSizeEvent& evt);

    int getWidth();
    int getHeight();

    void render(wxPaintEvent& evt);
    void prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
    void prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);

    // events
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);

    DECLARE_EVENT_TABLE()
protected:
private:

public:
protected:
private:
    wxGLContext *m_context;
    Form test;
};

#endif // CUSTOMGLPANE_H
