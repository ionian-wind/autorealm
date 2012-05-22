#ifndef ID_H
#define ID_H

#include <stdint.h>

class ID
{
	public:
		ID(void);
		ID(unsigned long id);
		const uint16_t operator()(void)const;
		operator int(void)const;
	protected:
	private:
	public:
	protected:
	private:
		static uint16_t s_nextID;
		uint16_t m_id;
};

#endif // ID_H
