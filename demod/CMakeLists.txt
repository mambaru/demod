include(Wfc)
include(BuildInfo)

include_directories(..)

add_executable(demod demod.cpp )

SET(
  demod_lib_list
  wfcroot
  wfc_demo
)

target_link_libraries(demod ${demod_lib_list})

add_dependencies(demod ${demod_lib_list})

build_info(demod demod)
