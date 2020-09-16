cmake_minimum_required(VERSION 3.1)

project(demod)

include(cmake/ci.cmake)

#option(WFC_ENABLE_STAT "Enable statistics components" ON)

wci_getlib(NAME wfcroot SUPERMODULE)
wci_getlib(NAME wfc_demo)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()

add_subdirectory(utils)

