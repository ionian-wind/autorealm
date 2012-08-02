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
#include <stdio.h> ///\todo find a way to use something like "struct FILE" like for classes

class TextFile
{
	boost::filesystem::path m_filePath;
	FILE *m_file;

public:
    /** \brief open an existing file
     *
     *	\param path boost::filesystem::path const& name of the file to open
     *	\return std::unique_ptr<TextFile> unique pointer to a TextFile object
     *	\pre given file exists
     *	\pre given file is a regular file
     *	\post file is open with cursor located at it's first byte
     */
	static std::unique_ptr<TextFile> OpenFile(boost::filesystem::path const &path);

    /** \brief create and open an inexisting file
     *
     *	\param file boost::filesystem::path const& name of the file to open
     *	\return std::unique_ptr<TextFile> unique pointer to a TextFile object
     *	\pre file does not exists
     *	\post file is created
     *	\post file is open with cursor located at it's first byte
     */
	static std::unique_ptr<TextFile> CreateFile(boost::filesystem::path const &file);

    /** \brief read an entire line and return it as a std::string
     *	\return std::string
     	\post file's cursors has been move to the next line or EOF if it was the last one
     */
	std::string readLine(void) throw();

	/** \brief indicate if eof has been reached
	 *
	 * \return bool true is EoF reached
	 * \invariant m_file is not altered
	 * \todo make the constness more consistent (see implementation for details)
	 */
	bool eofReached(void) const;

    /** \brief Dtor. Close file correctly. */
	~TextFile();

    /** \brief return name of opened file */
	std::string getFileName(void)const throw();
protected:
    /** \brief Ctor
     *	\param path and namefile of the file
     *	\param flag to know if we want to create a new file or not
     */
	TextFile(boost::filesystem::path const &file, bool create=false);
};

#endif // TEXTFILE_H
