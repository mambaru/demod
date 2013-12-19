cmake_minimum_required(VERSION 2.6)

project(cometd)

include_directories(wfc)
include_directories(faslib)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfc/cmake")

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -pedantic  -Wno-long-long -Wno-unused-variable -std=c++0x -DBOOST_SYSTEM_NO_DEPRECATED")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -Wno-unused-variable -std=c++0x -DBOOST_SYSTEM_NO_LIB -DBOOST_SYSTEM_NO_DEPRECATED")
#SET(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -ggdb -O2 -DNDEBUG")
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/comet/cmake")
#LIST (APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/comet/cmake")

add_subdirectory(wfc)
add_subdirectory(wfc_core)
add_subdirectory(wfc_config)
add_subdirectory(wfc_logger)
add_subdirectory(wfc_hub)
add_subdirectory(wfc_demo)

# release
# add_subdirectory(wfc/wfc)
# add_subdirectory(wfc_core/core)
# add_subdirectory(wfc_config/config)
# add_subdirectory(wfc_logger/logger)
# add_subdirectory(wfc_hub/hub)

add_subdirectory(demod)

