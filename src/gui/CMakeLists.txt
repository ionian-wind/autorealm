FILE(GLOB_RECURSE source_files *.cpp ${SRC}/utils/*.cpp)

ADD_EXECUTABLE(autorealm ${source_files})
TARGET_LINK_LIBRARIES(autorealm pluginengine renderengine ${wxWidgets_LIBRARIES})

