#include "id.h"

#include <stdexcept>

#include <wx/utils.h>

uint16_t ID::s_nextID=wxNewId();

ID::ID(void)
:m_id(s_nextID)
{
	if(0xFFFF==s_nextID)
		throw std::runtime_error("Can not manage more than 65536 (0xFFFF)ID.\nPlease send a bug report.");
	++s_nextID;
}

ID::ID(uint16_t id) throw()
:m_id(id)
{
}

inline const uint16_t ID::operator()(void)const throw()
{
	return m_id;
}

ID::operator uint16_t(void)const throw()
{
	return operator()();
}
