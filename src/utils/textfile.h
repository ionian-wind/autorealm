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
        /** \brief indicate if eof has been reached
         *
         * \param void
         * \return bool
         * \post m_file is not null
         * \pre m_file did not change
         * \todo make the constness more consistent (see implementation for details)
         */
		bool eofReached(void)const;
		~TextFile();
	protected:
		TextFile(boost::filesystem::path const &file, bool create=false);
	private:
		boost::filesystem::path m_filePath;
		FILE *m_file;
};

#endif // TEXTFILE_H
