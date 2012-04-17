#include "menuitem.h"

MenuItem::MenuItem()
{
	//ctor
}

MenuItem::~MenuItem()
{
	//dtor
}

void MenuItem::init(boost::filesystem::path const &file)
{
	m_name=file.filename().string();
}
