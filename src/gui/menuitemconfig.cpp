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
		("kind",po::value<MenuKind>(&m_kind)->multitoken())
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

MenuKind MenuItemConfig::kind(void)const
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

std::istream& operator>>(std::istream& in, MenuKind& kind)
{
	std::string token;
	in >> token;
	if (token == "separator")
		kind = MenuKind::SEPARATOR;
	else if (token == "normal")
		kind = MenuKind::NORMAL;
	else if (token == "check")
		kind = MenuKind::CHECK;
	else if (token == "radio")
		kind = MenuKind::RADIO;
	else
		throw po::validation_error(po::validation_error::kind_t::invalid_option,token,"kind");
	return in;
}

typedef Node<MenuItemConfig> _Folder;
typedef Leaf<MenuItemConfig> _File;

_Folder createTree(fs::path const& origin)
{
	_Folder f(origin);
	for(auto it=fs::directory_iterator(origin);it!=fs::directory_iterator();++it)
	{
		if(fs::is_directory(*it))
			f.push_back(createTree(*it));
		else if(it->path().filename().string()!=origin.filename().string())
			f.push_back(_File(MenuItemConfig(*it)));
	}
	return f;
}

wxMenuBar* createMenuFromFolder(_Folder & origin)
{
	wxMenuBar *menubar=new wxMenuBar();

	for(_Folder::iterator it=origin.begin();it!=origin.end();++it)
		if(it.isNode())
			menubar->Append(createMenu(dynamic_cast<_Folder&>(*it)),it->get().text());
		else
			throw std::runtime_error("menubar folder can only contain folders, because wxwidgets is only able to add wxMenu to wxMenubar");
	return menubar;
}

wxMenu* createMenu(_Folder & origin)
{
	///\note style is not supported because the only option is only available for GTK
	wxMenu *menu=origin.get().showTitle()?new wxMenu(origin.get().text()):new wxMenu();

	for(_Folder::iterator it=origin.begin();it!=origin.end();++it)
	{
		if(it.isNode())
		{
			_Folder &fold(dynamic_cast<_Folder&>(*it));
			menu->AppendSubMenu(createMenu(fold),fold.get().text(),fold.get().desc());
		}
		else
			menu->Append(it->get().id(),it->get().text(),it->get().desc(),it->get().kind());
	}

	return menu;
}
