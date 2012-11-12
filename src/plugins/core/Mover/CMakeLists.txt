FILE(GLOB_RECURSE source_files "*.cpp")

ADD_LIBRARY(Mover SHARED ${source_files} )
TARGET_LINK_LIBRARIES(Mover pluginengine ${wxWidgets_LIBRARIES} ${Pluma_LIBRARY})
