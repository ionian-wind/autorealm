#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../../interface/item.h"

class PolyLineTool : public Item
{
	public:
		void callback(wxCommandEvent& event);
		void readConfig(std::string const &graphicalResources);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(PolyLineTool,Item);
#endif // POLYLINETOOL_H
