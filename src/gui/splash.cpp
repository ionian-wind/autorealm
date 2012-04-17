#include "splash.h"

#include <wx/sizer.h>

#include "appconfig.h"
#include <utils/utils.h>

Splash::Splash()
:wxFrame(nullptr,-1,"")
{
	std::string filename(AppConfig::buildPath(AppConfig::INFO::GRP_RES)+"splash/splash.png");
	if(exists(boost::filesystem::path(filename)))
	{
		wxBoxSizer* BoxSizer1=new wxBoxSizer(wxHORIZONTAL);
		m_splash = new wxStaticBitmap(this, wxNewId(), loadImage("splash/splash.png"));
		BoxSizer1->Add(m_splash);
		SetSizer(BoxSizer1);
		BoxSizer1->Fit(this);
		Show();
	}
}

Splash::~Splash()
{
	//dtor
}
