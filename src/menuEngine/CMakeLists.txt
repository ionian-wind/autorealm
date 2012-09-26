FILE(GLOB_RECURSE source_files "wx*.cpp")

FIND_PACKAGE(Boost 1.39 COMPONENTS system filesystem REQUIRED)
ADD_LIBRARY(menuengine STATIC ${source_files})
TARGET_LINK_LIBRARIES(menuengine ${wxWidgets_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
