#ifndef LineTool_H
#define LineTool_H

#include <pluginEngine/item.h>

class LineTool : public Item
{
	public:
		LineTool(void);
		virtual void readConfig(FILE *file);
		virtual void action(wxEvent &);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(LineTool,Item)
#endif // INETOOL_H
