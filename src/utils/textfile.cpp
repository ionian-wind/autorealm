#include "textfile.h"

//#include <boost/filesystem.hpp>
//#include <stdio.h>

TextFile::TextFile(boost::filesystem::path const &file, bool create)
:m_filePath(file)
{
	if(create)
		throw std::logic_error("not implemented yet");
	m_file=fopen(m_filePath.string().c_str(),"r");
	if(!m_file)
		throw std::runtime_error("could not open file "+m_filePath.string());
}

TextFile::~TextFile()
{
	fclose(m_file);
}

std::unique_ptr<TextFile> TextFile::OpenFile(boost::filesystem::path const &file)
{
	if(!exists(file))
		throw std::runtime_error("File "+file.string()+" does not exists.");
	if(!is_regular_file(file))
		throw std::runtime_error("File "+file.string()+" is not a regular file.");
	return std::unique_ptr<TextFile>(new TextFile(file));
}

std::unique_ptr<TextFile> TextFile::CreateFile(boost::filesystem::path const &file)
{
	if(exists(file))
		throw std::runtime_error("File "+file.string()+" already exists.");
	return std::unique_ptr<TextFile>(new TextFile(file,true));
}

std::string TextFile::readLine(void)
{
	std::string result;
	char c;
	do
	{
		result.push_back(fgetc(m_file));
		c=result.back();
	}
	while(!feof(m_file) && c!='\n' && c!='\r');//!\note with those 2 characters, we should be fine on Mac OSand Linux operating systems. Problems will probably happens with MS Windows, because end of lines there are "\r\n" or "\n\r"
	result.resize(result.size()-1);

	return result;
}
