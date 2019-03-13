cmake_minimum_required(VERSION 3.1)

project(demod)

include(cmake/ci.cmake)

wfcroot(wfc_demo)

include_directories(.)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()

if ( WITH_SAMPLES )
  add_subdirectory(utils)
endif()

