FILE(GLOB_RECURSE source_files "*.cpp")

ADD_LIBRARY(LineMonoColor SHARED ${source_files} )
TARGET_LINK_LIBRARIES(LineMonoColor pluginengine ${wxWidgets_LIBRARIES} ${Pluma_LIBRARY})
