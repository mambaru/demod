cmake_minimum_required(VERSION 3.1)

project(demod)

include(cmake/ci.cmake)

wfcroot(wfc_demo)

include_directories(.)

add_subdirectory(utils)
add_subdirectory(daemon)

