cmake_minimum_required(VERSION 2.6)

project(wfc_demo)

#if ( NOT WFC_READY )
#  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/wfc/cmake")
#  include(Wfc)
#endif()

include(BuildInfo)

include_directories(..)

add_executable(demod demod.cpp )

SET(demod_libraries wfcroot wfc_demo)

target_link_libraries(demod ${demod_libraries})

add_dependencies(demod ${demod_libraries})

build_info(demod demod)
