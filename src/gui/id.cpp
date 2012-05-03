#include "id.h"

#include <wx/utils.h>
uint16_t ID::s_nextID=wxNewId();

ID::ID()
:m_id(s_nextID)
{
	++s_nextID;
}

const uint16_t ID::operator()(void)const
{
	return m_id;
}

ID::operator int(void)const
{
	return m_id;
}
