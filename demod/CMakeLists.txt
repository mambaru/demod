include(Wfc)
include(BuildInfo)

include_directories(..)

add_executable(demod demod.cpp )

SET(demod_libraries wfcroot wfc_demo)

target_link_libraries(demod ${demod_libraries})

add_dependencies(demod ${demod_libraries})

build_info(demod demod)
