#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <boost/filesystem.hpp>
#include <stdio.h>

class TextFile
{
	public:
		static std::unique_ptr<TextFile> OpenFile(boost::filesystem::path const &path);
		static std::unique_ptr<TextFile> CreateFile(boost::filesystem::path const &file);
		std::string readLine(void);
		~TextFile();
	protected:
		TextFile(boost::filesystem::path const &file, bool create=false);
	private:
		boost::filesystem::path m_filePath;
		FILE *m_file;
};

#endif // TEXTFILE_H
