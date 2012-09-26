FILE(GLOB_RECURSE source_files "*.cpp")

FIND_PACKAGE(OpenGL)
ADD_LIBRARY(renderengine SHARED ${source_files})
TARGET_LINK_LIBRARIES(renderengine ${OPENGL_LIBRARIES})
