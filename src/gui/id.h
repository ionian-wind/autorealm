#ifndef ID_H
#define ID_H

#include <stdint.h>

class ID
{
	static uint16_t s_nextID;
	const uint16_t m_id;
public:
	/** \brief take an unused ID number
	 *	\pre s_nextID != 0xFFFF
	 *	\post s_nextID is incremented
	 */
	ID(void);
	/** \brief copy an ID number
	 *	\invariant s_nextID
	 *	\param id unsigned long
	 */
	ID(uint16_t id) throw();
	/** \brief get the stored number
	 * \return const uint16_t
	 */
	const uint16_t operator()(void)const throw();
	/** \brief cast operator to int
	 *	\return copy of m_id
	 */
	operator uint16_t(void)const throw();
};

#endif // ID_H
