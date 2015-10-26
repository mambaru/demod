
add_executable(demod demod.cpp )

set(demod_libraries wfcroot wfc_demo)

target_link_libraries(demod ${demod_libraries})

add_dependencies(demod ${demod_libraries})

include(BuildInfo)

build_info(demod demod)
