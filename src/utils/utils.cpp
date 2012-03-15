#include "utils.h"

/** \brief retrieve a line from a text file
 * \todo use locales?
 * \todo use wide characters? (aka unicode)
 * \todo replace with something more standard if any
 * \param source FILE*
 * \return std::string
 *
 */
std::string readline(FILE *source)
{
	std::string result;
	char c;
	do
	{
		result.push_back(fgetc(source));
		c=result.back();
	}
	while(!feof(source) && c!='\n' && c!='\r');//!\note with those 2 characters, we should be fine on Mac OSand Linux operating systems. Problems will probably happens with MS Windows, because end of lines there are "\r\n" or "\n\r"
	result.resize(result.size()-1);

	return result;
}

bool eofReached(FILE *source)
{
	long int current_pos=ftell(source);
	bool result=true;

	fseek(source,0,SEEK_END);
	result=current_pos==ftell(source);
	fseek(source,current_pos,SEEK_SET);
	return result;
}
