#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

#include "../DrawingTool.h"


class PolyLineTool : public DrawingTool
{
	public:
		PolyLineTool();
		void callback(wxCommandEvent& event);
	protected:
	private:
};

#endif // POLYLINETOOL_H
