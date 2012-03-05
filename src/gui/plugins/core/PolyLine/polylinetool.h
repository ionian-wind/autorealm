#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../../interface/item.h"

class PolyLineTool : public Item
{
	public:
		void readConfig(std::string const &graphicalResources);

void onClick(wxCommandEvent& event);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(PolyLineTool,Item);
#endif // POLYLINETOOL_H
