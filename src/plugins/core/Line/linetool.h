#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../../pluginEngine/item.h"

class LineTool : public Item
{
	public:
		LineTool(void);
		virtual void readConfig(AppConfig const& config, FILE *file);
		virtual void action(wxEvent &);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(LineTool,Item)
#endif // POLYLINETOOL_H
