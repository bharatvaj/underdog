cmake_minimum_required (VERSION 2.8)
project (underdog)

find_package(Threads REQUIRED)
find_package(FLTK REQUIRED)

set (CMAKE_CXX_FLAGS "-lsqlite3 -fPIC -Wall")

##version number
set (underdog_VERSION_MAJOR 0)
set (underdog_VERSION_MINOR 4)
set (DEFAULT_PORT 12300)

option(ENABLE_LOG
	"Enable debugging" OFF)
if(ENABLE_LOG)
	add_definitions(-DENABLE_LOG)
endif(ENABLE_LOG)

#miscellaneous
set (BUFFER_SIZE 256)

#configure file to add CMake settings to it
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_SOURCE_DIR}/config.h"
	)
include_directories ("${PROJECT_BINARY_DIR}")
add_executable (underdog underdog.cpp)
target_link_libraries(underdog ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(underdog ${FLTK_LIBRARIES})
