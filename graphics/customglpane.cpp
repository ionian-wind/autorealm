#include "customglpane.h"

BEGIN_EVENT_TABLE(CustomGLPane, wxGLCanvas)
EVT_MOTION(CustomGLPane::mouseMoved)
EVT_LEFT_DOWN(CustomGLPane::mouseDown)
EVT_LEFT_UP(CustomGLPane::mouseReleased)
EVT_RIGHT_DOWN(CustomGLPane::rightClick)
EVT_LEAVE_WINDOW(CustomGLPane::mouseLeftWindow)
EVT_SIZE(CustomGLPane::resized)
EVT_KEY_DOWN(CustomGLPane::keyPressed)
EVT_KEY_UP(CustomGLPane::keyReleased)
EVT_MOUSEWHEEL(CustomGLPane::mouseWheelMoved)
EVT_PAINT(CustomGLPane::render)
END_EVENT_TABLE()


// some useful events to use
void CustomGLPane::mouseMoved(wxMouseEvent& event) {}
void CustomGLPane::mouseDown(wxMouseEvent& event) {}
void CustomGLPane::mouseWheelMoved(wxMouseEvent& event) {}
void CustomGLPane::mouseReleased(wxMouseEvent& event) {}
void CustomGLPane::rightClick(wxMouseEvent& event) {}
void CustomGLPane::mouseLeftWindow(wxMouseEvent& event) {}
void CustomGLPane::keyPressed(wxKeyEvent& event) {}
void CustomGLPane::keyReleased(wxKeyEvent& event) {}

CustomGLPane::CustomGLPane(wxFrame* parent, int* args) :
    wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
	m_context = new wxGLContext(this);

    // To avoid flashing on MSW
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    test.AddPoint(D3Point(0,0,0));
    test.AddPoint(D3Point(1,1,0));
    test.AddPoint(D3Point(1,0,0));
    test.setBorder(Color(0.5,1.0,1.0,1.0));
    test.setFiller(Color(1,0,0,1.0));
}

CustomGLPane::~CustomGLPane()
{
	delete m_context;
}

void CustomGLPane::resized(wxSizeEvent& evt)
{
//	wxGLCanvas::OnSize(evt);

    Refresh();
}

/** Inits the OpenGL viewport for drawing in 3D. */
void CustomGLPane::prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y)
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black Background
    glClearDepth(1.0f);	// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_COLOR_MATERIAL);

    glViewport(topleft_x, topleft_y, bottomrigth_x-topleft_x, bottomrigth_y-topleft_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float ratio_w_h = (float)(bottomrigth_x-topleft_x)/(float)(bottomrigth_y-topleft_y);
    gluPerspective(45 /*view angle*/, ratio_w_h, 0.1 /*clip close*/, 200 /*clip far*/);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

/** Inits the OpenGL viewport for drawing in 2D. */
void CustomGLPane::prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y)
{
    glEnable(GL_TEXTURE_2D);   // textures
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glViewport(topleft_x, topleft_y, bottomrigth_x-topleft_x, bottomrigth_y-topleft_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(topleft_x, bottomrigth_x, bottomrigth_y, topleft_y);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int CustomGLPane::getWidth()
{
    return GetSize().x;
}

int CustomGLPane::getHeight()
{
    return GetSize().y;
}


void CustomGLPane::render( wxPaintEvent& evt )
{
    if(!IsShown()) return;

    wxGLCanvas::SetCurrent(*m_context);
    wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    // ------------- draw some 2D ----------------
//    prepare2DViewport(0,0,getWidth()/2, getHeight());
    // ------------- draw some 3D ----------------
//    prepare3DViewport(getWidth()/2,0,getWidth(), getHeight());
    glLoadIdentity();
    test.Draw();

    glFlush();
    SwapBuffers();
}
