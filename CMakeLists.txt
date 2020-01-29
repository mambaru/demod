cmake_minimum_required(VERSION 3.1)

project(demod)

#TODO: разобраться, перенести в wfc и подключать через include(
set(WFC_ENABLE_STAT OFF)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWFC_ENABLE_STAT=OFF")
remove_definitions(-DWFC_ENABLE_STAT)
include(cmake/ci.cmake)
#wci_add_options(-DWFC_ENABLE_STAT=ON)
wci_getlib(NAME wfcroot SUPERMODULE)
wci_getlib(NAME wfc_demo)

add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()

add_subdirectory(utils)

