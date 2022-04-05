
add_executable(wfcd wfcd.cpp )
add_executable(cored cored.cpp )
add_executable(wfcrootd wfcrootd.cpp )
add_executable(demod demod.cpp )

wci_targets(wfcd cored wfcrootd demod )

target_link_libraries(wfcd PUBLIC wfc)
target_link_libraries(cored PUBLIC wfc wfc_core)
target_link_libraries(wfcrootd PUBLIC wfcroot)
target_link_libraries(demod PUBLIC wfcroot wfc_demo)

build_info(TARGET demod PREFIX demod)
build_info(TARGET wfcrootd PREFIX demod LINK)
build_info(TARGET cored PREFIX demod LINK)
build_info(TARGET wfcd PREFIX demod LINK)

