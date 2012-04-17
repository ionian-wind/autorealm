#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

#include <boost/filesystem.hpp>

class MenuItem
{
	public:
		virtual ~MenuItem();
	protected:
		MenuItem(void);
		void init(boost::filesystem::path const &file);
	private:
		std::string m_name;
};

#endif // MENUITEM_H
