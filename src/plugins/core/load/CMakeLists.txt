FILE(GLOB_RECURSE source_files "*.cpp")

FIND_PACKAGE(Boost 1.39 COMPONENTS serialization REQUIRED)
ADD_LIBRARY(load SHARED ${source_files} )
TARGET_LINK_LIBRARIES(load pluginengine renderengine ${wxWidgets_LIBRARIES} ${Pluma_LIBRARY} ${Boost_SERIALIZATION_LIBRARY})
