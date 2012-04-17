#include "menu.h"

#include "item.h"

Menu::Menu(boost::filesystem::path const &location)
:MenuItem()
{
	for(auto content=boost::filesystem::directory_iterator(location);content!=boost::filesystem::directory_iterator();++content)
	{
		if(boost::filesystem::is_regular_file(content->path()))
		{
			// do the file have the same name as it's directory?
			if(0==location.filename().string().compare(content->path().filename().string()))
				MenuItem::init(*content);
			else
				m_leaves.push_back(std::unique_ptr<MenuItem>(new Item(content->path())));
		}
		else
			m_leaves.push_back(std::unique_ptr<MenuItem>(new Menu(content->path())));
	}
}

Menu::~Menu()
{
	//dtor
}
