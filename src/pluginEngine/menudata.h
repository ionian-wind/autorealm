#ifndef MENU_DATA_H
#define MENU_DATA_H

#include <string>
#include <stdexcept>

#include <wx/frame.h>
#include "../utils/utils.h"

struct MenuData
{
public:
	wxItemKind kind;
	std::string help;
	std::string name;
protected:
private:
	std::string m_corruptedFile;

public:
	MenuData(std::string const &nAME, std::string const& hELP, wxItemKind const kIND)
	:kind(kIND),help(hELP),name(nAME)
	{
		m_corruptedFile=("configuration file corrupted\n");
		checkName();
	}

	MenuData(void)
	:kind(wxITEM_NORMAL),help(""),name()
	{
		m_corruptedFile=("configuration file corrupted\n");
	}

	void readFromFile(FILE * source)
	{
		try
		{
			name=readline(source);
			help=readline(source);
			std::string tmp(readline(source));
			sscanf(tmp.c_str(),"%d",(int*)(&kind));
		}
		catch(std::runtime_error &e)
		{
			std::string err(m_corruptedFile);
			err+=e.what();
			throw std::runtime_error(err);
		}
		checkName();
	}

protected:
	void checkName(void)
	{
		if(name.empty())
			throw std::runtime_error("item without name are not allowed");
	}
private:
};

#endif
