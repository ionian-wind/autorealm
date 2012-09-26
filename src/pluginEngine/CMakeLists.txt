FILE(GLOB_RECURSE source_files "*.cpp")

ADD_LIBRARY(pluginengine SHARED ${source_files} )
TARGET_LINK_LIBRARIES(pluginengine ${wxWidgets_LIBRARIES} ${Pluma_LIBRARY})
