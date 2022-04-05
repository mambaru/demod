
add_executable(wonderwaffel0 wonderwaffel0.cpp)
add_executable(wonderwaffel wonderwaffel.cpp)

wci_utils(wonderwaffel0 wonderwaffel)
enable_stat(wonderwaffel0 wonderwaffel)

target_link_libraries(wonderwaffel0 PRIVATE wfcroot wfc_demo)
target_link_libraries(wonderwaffel PRIVATE wfcroot wfc_demo)

build_info(TARGET wonderwaffel)
build_info(TARGET wonderwaffel0)
