
add_executable(demod demod.cpp )

set(demod_libraries wfcroot wfc_demo)

target_link_libraries(demod wfcroot wfc_demo)

add_dependencies(demod wfcroot wfc_demo)

include(BuildInfo)

build_info(demod demod)

