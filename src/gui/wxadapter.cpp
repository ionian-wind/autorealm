#include "wxadapter.h"
#include <string>
#include <boost/program_options.hpp>

namespace po=boost::program_options;
namespace fs=boost::filesystem;

std::istream& operator>>(std::istream& in, ItemKind& kind)
{
	std::string token;
	in >> token;
	if(token == "separator")
		kind= ItemKind::SEPARATOR;
	else if(token == "normal")
		kind= ItemKind::NORMAL;
	else if(token == "check")
		kind= ItemKind::CHECK;
	else if(token == "radio")
		kind= ItemKind::RADIO;
	else
		throw po::validation_error(po::validation_error::invalid_option, token, "kind");
	return in;
}
