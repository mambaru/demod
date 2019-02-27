cmake_minimum_required(VERSION 3.1)

project(demod)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(ci)
wfcroot()
getlibs(wfc_demo)

include(Wfc)
include_directories(.)

add_subdirectory(utils)
add_subdirectory(daemon)

