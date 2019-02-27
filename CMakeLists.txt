cmake_minimum_required(VERSION 3.1)

project(demod)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ci)
getlibs(wfcroot)
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "!----> dir='${dir}'")
endforeach()
#??
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/wfcroot/external/wfc/cmake)
#??
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/wfc)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/iow)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/wjson)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/faslib)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/wlog)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/wflow)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/wrtstat)
include_directories(${CMAKE_SOURCE_DIR}/external/wfcroot/external/wjrpc)
include_directories(${CMAKE_SOURCE_DIR}/external/)
getlibs(wfc_demo)

include(Wfc)

include_directories(.)

add_subdirectory(utils)
add_subdirectory(daemon)

