#ifndef WXADAPTER_H
#define WXADAPTER_H

#include <istream>
#include <wx/menu.h>
#include <boost/filesystem.hpp>
#include <tree.h>

enum ItemKind
{
	SEPARATOR=wxITEM_SEPARATOR,
	NORMAL=wxITEM_NORMAL,
	CHECK=wxITEM_CHECK,
	RADIO=wxITEM_RADIO
};

std::istream& operator>>(std::istream& in, ItemKind& kind);

template <typename NodeType>
Node<NodeType> createTree(boost::filesystem::path const& origin)
{
	Node<NodeType> f(origin);
	for(auto it=boost::filesystem::directory_iterator(origin);it!=boost::filesystem::directory_iterator();++it)
	{
		if(boost::filesystem::is_directory(*it))
			f.push_back(createTree<NodeType>(*it));
		else if(it->path().filename().string()!=origin.filename().string())
			f.push_back(Leaf<NodeType>(NodeType(*it)));
	}
	return f;
}

#endif
