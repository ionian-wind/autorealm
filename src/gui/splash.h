#ifndef SPLASH_H
#define SPLASH_H

#include <wx/frame.h>
#include <wx/statbmp.h>

class Splash: public wxFrame
{
public:
	Splash();
	~Splash();
protected:
private:
private:
	wxStaticBitmap *m_splash=nullptr;
};

#endif
