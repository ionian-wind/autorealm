#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../../pluginEngine/item.h"

class PolyLineTool : public Item
{
	public:
		PolyLineTool(void);
		virtual void readConfig(AppConfig const& config, FILE *file);
		virtual void action(wxEvent&ev);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(PolyLineTool,Item)
#endif // POLYLINETOOL_H
