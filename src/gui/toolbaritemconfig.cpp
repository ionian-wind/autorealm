#include "toolbaritemconfig.h"
#include "id.h"
#include "appconfig.h"

ToolbarItemConfig::ToolbarItemConfig(fs::path const& rootDir)
:m_path(rootDir)
{
	std::string filename(m_path.string());

	if(fs::is_directory(rootDir))
		filename+="/"+m_path.filename().string();

	std::ifstream ifs(filename);
	if(!ifs)
		throw std::runtime_error("unable to open file: "+filename);

	po::options_description file("File");
	file.add_options()
		("label", po::value<std::string>(&m_label))
		("bitmap", po::value<std::string>(&m_bmp))
		("description", po::value<std::string>(&m_desc))
		("plugin",po::value<std::string>(&m_plugin))
		("kind",po::value<ItemKind>(&m_kind)->multitoken())
		;
	po::variables_map vm;
	store(parse_config_file(ifs, file), vm);
	notify(vm);
}

ToolbarItemConfig::ToolbarItemConfig(ToolbarItemConfig && other)
:m_label(std::move(other.m_label))
,m_bmp(std::move(other.m_bmp))
,m_desc(std::move(other.m_desc))
,m_plugin(std::move(other.m_plugin))
,m_kind(std::move(other.m_kind))
{
}

ToolbarItemConfig::ToolbarItemConfig(ToolbarItemConfig const& other)
:m_label(other.m_label)
,m_bmp(other.m_bmp)
,m_desc(other.m_desc)
,m_plugin(other.m_plugin)
,m_kind(other.m_kind)
{
}

std::string ToolbarItemConfig::label(void)const
{
	return m_label;
}

std::string ToolbarItemConfig::bmp(void)const
{
	return m_bmp;
}

std::string ToolbarItemConfig::desc(void)const
{
	return m_desc;
}

std::string ToolbarItemConfig::plugin(void)const
{
	return m_plugin;
}

ItemKind ToolbarItemConfig::kind(void)const
{
	return m_kind;
}

uint16_t ToolbarItemConfig::id(void)const
{
	return m_id;
}

void ToolbarItemConfig::setId(uint16_t id)
{
	m_id=id;
}

void buildToolbars(wxAuiManager &mgr,Node<ToolbarItemConfig> & origin, wxWindow *parent)
{
	for(auto it=origin.begin();it!=origin.end();++it)
	{
		if(it.isNode())
			mgr.AddPane(buildPaneComponents(dynamic_cast<Node<ToolbarItemConfig>&>(*it),parent),buildPaneInfo(*it));
		else
			throw std::runtime_error("root toolbar folder should only contain directories");
	}
	mgr.Update();
}

wxAuiToolBar* buildPaneComponents(Node<ToolbarItemConfig> &data, wxWindow *parent)
{
int id=-1;///\todo bind a true id
	wxAuiToolBar *ret=new wxAuiToolBar(parent);
	for(auto it=data.begin();it!=data.end();++it)
//		if(it.isNode())
			ret->AddTool(
				id,
				it->get().label(),
				wxBitmap(wxImage(AppConfig::buildPath(AppConfig::GRP_RES) +it->get().bmp())),
				it->get().desc(),
				static_cast<wxItemKind>(it->get().kind())
			);
//		else
//			throw std::runtime_error("toolbar children folders should only contain files");

	ret->Realize();
	return ret;
}

wxAuiPaneInfo buildPaneInfo(Leaf<ToolbarItemConfig> &data)
{
	return wxAuiPaneInfo();
}
