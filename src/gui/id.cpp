#include "id.h"

#include <wx/utils.h>
uint16_t ID::s_nextID=wxNewId();

ID::ID(void)
:m_id(s_nextID)
{
	++s_nextID;
}

ID::ID(unsigned long id)
:m_id(id)
{
}

const uint16_t ID::operator()(void)const
{
	return m_id;
}

ID::operator int(void)const
{
	return operator()();
}
