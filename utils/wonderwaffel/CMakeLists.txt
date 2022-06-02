
add_executable(wonderwaffel0 wonderwaffel0.cpp)
add_executable(wonderwaffel1 wonderwaffel.cpp)

wci_utils(wonderwaffel0 wonderwaffel1)
enable_stat(wonderwaffel0 wonderwaffel1)

target_link_libraries(wonderwaffel0 PRIVATE wfcroot wfc_demo)
target_link_libraries(wonderwaffel1 PRIVATE wfcroot wfc_demo)

build_info(TARGET wonderwaffel1)
build_info(TARGET wonderwaffel0)
