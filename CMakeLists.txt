cmake_minimum_required(VERSION 3.1)

project(demod)

include(cmake/ci.cmake)

wci_getlib(NAME wfcroot SUPERMODULE)
wci_getlib(NAME wfc_demo)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()

if ( WITH_SAMPLES )
  add_subdirectory(utils)
endif()

