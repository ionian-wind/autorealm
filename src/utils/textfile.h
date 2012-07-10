/**********************************************************************************
 *autorealm - A vectorized graphic editor to create maps, mostly for RPG games    *
 *Copyright (C) 2012 Morel Bérenger                                               *
 *                                                                                *
 *This file is part of autorealm.                                                 *
 *                                                                                *
 *    autorealm is free software: you can redistribute it and/or modify           *
 *    it under the terms of the GNU Lesser General Public License as published by *
 *    the Free Software Foundation, either version 3 of the License, or           *
 *    (at your option) any later version.                                         *
 *                                                                                *
 *    autorealm is distributed in the hope that it will be useful,                *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *    GNU Lesser General Public License for more details.                         *
 *                                                                                *
 *    You should have received a copy of the GNU Lesser General Public License    *
 *    along with autorealm.  If not, see <http://www.gnu.org/licenses/>.          *
 **********************************************************************************/

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
		std::string getFileName(void)const;
	protected:
		TextFile(boost::filesystem::path const &file, bool create=false);
	private:
		boost::filesystem::path m_filePath;
		FILE *m_file;
};

#endif // TEXTFILE_H
