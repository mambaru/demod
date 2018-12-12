cmake_minimum_required(VERSION 3.1)

project(demod)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ci)

add_subdirectory(wfcroot)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake)
include(Wfc)

include_directories(.)
add_subdirectory(demod)
add_subdirectory(utils)
add_subdirectory(wfc_demo)

