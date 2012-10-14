#ifndef DRAWERLIST_H
#define DRAWERLIST_H

#include <gui/singleton.h>

class DrawerList : public Singleton<DrawerList>
{
public:
	std::vector<Drawer*> m_drawerList;///\todo replace with a ptr_list
};

#endif
