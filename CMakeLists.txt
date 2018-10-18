cmake_minimum_required(VERSION 2.6)

project(demod)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfcroot/wfc/cmake")
include(mambaopt)
include(Wfc)

include_directories(.)

add_subdirectory(wfcroot)
add_subdirectory(wfc_demo)
add_subdirectory(demod)
