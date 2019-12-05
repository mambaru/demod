
add_executable(demod demod.cpp )

wci_targets(demod)

target_link_libraries(demod PUBLIC wfcroot wfc_demo)

build_info(demod demod)

