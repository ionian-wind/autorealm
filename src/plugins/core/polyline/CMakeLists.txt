FILE(GLOB_RECURSE source_files "*.cpp")

ADD_LIBRARY(polyline SHARED ${source_files} )
TARGET_LINK_LIBRARIES(polyline pluginengine ${wxWidgets_LIBRARIES} ${Pluma_LIBRARY})
