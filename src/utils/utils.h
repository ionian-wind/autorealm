#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string>

#include <wx/bitmap.h>

#include "../gui/appconfig.h"
class MainFrame;
class Container;

std::string readline(FILE *source);
bool eofReached(FILE *source);
/** \brief open an image from disk if it exists
 *
 * \param fileName std::string const&
 * \param config AppConfig const&
 * \return wxBitmap
 */
wxBitmap loadImage(std::string const & fileName);

#endif // UTILS_H
