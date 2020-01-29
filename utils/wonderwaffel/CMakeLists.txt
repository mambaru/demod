add_executable(wonderwaffel wonderwaffel.cpp)
wci_utils(wonderwaffel)
target_link_libraries(wonderwaffel PRIVATE wfcroot wfc_demo)
