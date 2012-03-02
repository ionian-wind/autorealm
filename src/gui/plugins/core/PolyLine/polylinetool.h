#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../../interface/item.h"

class PolyLineTool : public Item
{
	public:
		PolyLineTool(void);
		void callback(wxCommandEvent& event);
		void readConfig(void);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(PolyLineTool,Item);
#endif // POLYLINETOOL_H
