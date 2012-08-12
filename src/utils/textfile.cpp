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

#include "textfile.h"

#include <stdio.h>

TextFile TextFile::OpenFile(boost::filesystem::path const &file)
{
	if(!exists(file))
		throw std::runtime_error("File " + file.string() + " does not exists.");

	if(!is_regular_file(file))
		throw std::runtime_error("File " + file.string() + " is not a regular file.");

	return TextFile(file);
}

TextFile TextFile::OpenFile(std::string const &directory, std::string const &file)
{
	return TextFile::OpenFile(boost::filesystem::path(directory + file));
}

TextFile TextFile::CreateFile(boost::filesystem::path const &file)
{
	if(exists(file))
		throw std::runtime_error("File " + file.string() + " already exists.");

	return TextFile(file, true);
}

std::string TextFile::readLine(void) throw()
{
	std::string result;
	char c;

	do
		result.push_back((c=fgetc(m_file)));
	while(!feof(m_file) && c != '\n' && c != '\r'); //!\note should be fine on MacOS and Linux. Problems could happens with MS Windows, because EoL uses both.

	result.resize(result.size() - 1);
	return result;
}

bool TextFile::eofReached(void) const
{
	/**
	\todo How to make the constness more consistent:

	reopen the file in h2
	move h2's cursor to the end of the file
	measure h2's cursor's position
	measure m_file's cursor's position
	compare both positions

	easy to implement, but need to check that a file can be opened twice in standard
	*/
	long int current_pos = ftell(m_file);
	fseek(m_file, 0, SEEK_END);
	bool result = current_pos == ftell(m_file);
	fseek(m_file, current_pos, SEEK_SET);
	return result;
}

TextFile::~TextFile()
{
	fclose(m_file);
}

std::string TextFile::getFileName(void)const throw()
{
	return m_filePath.filename().string();
}

TextFile::TextFile(boost::filesystem::path const &file, bool create)
	: m_filePath(file)
{
	if(create)
		m_file = fopen(m_filePath.string().c_str(), "w");

	m_file = fopen(m_filePath.string().c_str(), "r");

	if(!m_file)
		throw std::runtime_error("could not open file " + m_filePath.string());
}
