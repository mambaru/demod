add_executable(wtelnet wtelnet.cpp tcpclient.cpp udpclient.cpp )
update_ogenc(TARGETS wtelnet OFF WARNINGS "-Wnull-dereference")
wci_utils(wtelnet)
target_link_libraries(wtelnet PRIVATE iow)
