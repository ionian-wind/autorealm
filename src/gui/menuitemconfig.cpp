#include "menuitemconfig.h"
#include "id.h"

MenuItemConfig::MenuItemConfig(fs::path const& rootDir)
:m_path(rootDir),m_text(),m_desc()
{
	std::string filename(m_path.string());

	if(fs::is_directory(rootDir))
		filename+="/"+m_path.filename().string();

	std::ifstream ifs(filename);
	if(!ifs)
		throw std::runtime_error("unable to open file: "+filename);

	po::options_description file("File");
	file.add_options()
		("text", po::value<std::string>(&m_text))
		("description", po::value<std::string>(&m_desc))
		("kind",po::value<ItemKind>(&m_kind)->multitoken())
		("plugin",po::value<std::string>(&m_plugin))
		;
	po::variables_map vm;
	store(parse_config_file(ifs, file), vm);
	notify(vm);
}

MenuItemConfig::MenuItemConfig(MenuItemConfig && other)
:m_path(std::move(other.m_path))
,m_text(std::move(other.m_text))
,m_desc(std::move(other.m_desc))
,m_plugin(std::move(other.m_plugin))
,m_kind(std::move(other.m_kind))
,m_showTitle(std::move(other.m_showTitle))
{
}

MenuItemConfig::MenuItemConfig(MenuItemConfig const& other)
:m_path(other.m_path)
,m_text(other.m_text)
,m_desc(other.m_desc)
,m_plugin(other.m_plugin)
,m_kind(other.m_kind)
,m_showTitle(other.m_showTitle)
{
}

std::string MenuItemConfig::loc(void)const
{
	return m_path.string();
}

std::string MenuItemConfig::text(void)const
{
	return m_text;
}

std::string MenuItemConfig::desc(void)const
{
	return m_desc;
}

std::string MenuItemConfig::plugin(void)const
{
	return m_plugin;
}

ItemKind  MenuItemConfig::kind(void)const
{
	return m_kind;
}

bool MenuItemConfig::showTitle(void)const
{
	return m_showTitle;
}

uint16_t MenuItemConfig::id(void)const
{
	return m_id;
}

void MenuItemConfig::setId(uint16_t id)
{
	m_id=id;
}

wxMenuBar* createMenuFromFolder(Node<MenuItemConfig> & origin)
{
	wxMenuBar *menubar=new wxMenuBar();

	for(Node<MenuItemConfig>::iterator it=origin.begin();it!=origin.end();++it)
		if(it.isNode())
			menubar->Append(createMenu(dynamic_cast<Node<MenuItemConfig>&>(*it)),it->get().text());
		else
			throw std::runtime_error("menubar folder can only contain folders, because wxwidgets is only able to add wxMenu to wxMenubar");
	return menubar;
}

wxMenu* createMenu(Node<MenuItemConfig> & origin)
{
	///\note style is not supported because the only option is only available for GTK
	wxMenu *menu=origin.get().showTitle()?new wxMenu(origin.get().text()):new wxMenu();

	for(Node<MenuItemConfig>::iterator it=origin.begin();it!=origin.end();++it)
	{
		if(it.isNode())
		{
			Node<MenuItemConfig> &fold(dynamic_cast<Node<MenuItemConfig>&>(*it));
			menu->AppendSubMenu(createMenu(fold),fold.get().text(),fold.get().desc());
		}
		else
			menu->Append(it->get().id(),it->get().text(),it->get().desc(),it->get().kind());
	}

	return menu;
}
