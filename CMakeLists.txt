cmake_minimum_required(VERSION 3.10)

project(demod VERSION "0.9.8")

include(cmake/ci.cmake)

set(ENABLE_STAT ON CACHE BOOL "Принудительное включение статистики" FORCE )
wci_submodule(NAME wfcroot SUPERMODULE)
wci_submodule(NAME wfc_demo )


add_subdirectory(daemon)

if ( BUILD_TESTING )
  enable_testing()
  add_subdirectory(tests)
endif()

add_subdirectory(utils)

include(cmake/install.cmake)
