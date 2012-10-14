#include "taglist.h"

namespace Render
{
TagList::TagList(void)=default;

TagList::TagList(std::string const& str)
:m_tags(str)
{
}

TagList& TagList::operator+=(std::string const & newTag)
{
	m_tags+=" "+newTag;
	return *this;
}

bool TagList::operator==(TagList const& other)const
{
	return m_tags==other.m_tags;
}
}
