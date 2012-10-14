#ifndef TAGLIST_H
#define TAGLIST_H

#include <string>

namespace Render
{
class TagList
{
	std::string m_tags;
public:
	TagList(void);
	TagList(std::string const& str);
	TagList& operator+=(std::string const & newTag);
	bool operator==(TagList const& other)const;
protected:
private:
};
}
#endif // TAGLIST_H
