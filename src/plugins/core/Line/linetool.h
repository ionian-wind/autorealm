#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../../pluginEngine/item.h"

class LineTool : public Item
{
	public:
		/** \brief Dumb, Stupid, and Useless method made for testing, while the plug-in architecture does not work
		 *	\todo Remove me
		 */
		void DumbMethod(wxCommandEvent& event);

		LineTool(void);
		virtual void readConfig(AppConfig const& config, FILE *file);

void onClick(wxCommandEvent& event);
	protected:
	private:
};

PLUMA_INHERIT_PROVIDER(LineTool,Item)
#endif // POLYLINETOOL_H
