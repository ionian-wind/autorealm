#include "id.h"

uint16_t ID::s_nextID=0;

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
