CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
PROJECT(AutoREALM)
set (AutoREALM_VERSION_MAJOR 1)
set (AutoREALM_VERSION_MINOR 6)

ENABLE_LANGUAGE(CXX)

set(Pluma_LIBRARY /usr/local/lib/libpluma.so)

FIND_PACKAGE(wxWidgets REQUIRED base core adv gl aui)
INCLUDE(${wxWidgets_USE_FILE})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(SRC "${CMAKE_SOURCE_DIR}/src")
INCLUDE_DIRECTORIES(${SRC})
SUBDIRS(${SRC})
SET(CONFIG "${CMAKE_SOURCE_DIR}/config/autorealm")

SET(EXECUTABLE_OUTPUT_PATH
	${CMAKE_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH
	${CMAKE_SOURCE_DIR}/bin)


INSTALL(FILES ${CMAKE_SOURCE_DIR}/bin/libpolyline.so ${CMAKE_SOURCE_DIR}/bin/libMover.so ${CMAKE_SOURCE_DIR}/bin/libload.so ${CMAKE_SOURCE_DIR}/bin/libsave.so DESTINATION /usr/local/lib/autorealm/plugin/)


INSTALL(FILES ${CONFIG}/config DESTINATION /usr/local/etc/autorealm/)
FILE(INSTALL ${CONFIG}/menubar DESTINATION /usr/local/etc/autorealm/)
FILE(INSTALL ${CONFIG}/png_files DESTINATION /usr/local/share/autorealm/)

