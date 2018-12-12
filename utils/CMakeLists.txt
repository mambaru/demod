project(wtelnet)


include_directories("${CMAKE_SOURCE_DIR}/wfcroot/iow")
include_directories("${CMAKE_SOURCE_DIR}/wfcroot/wlog")

add_executable(wtelnet wtelnet.cpp tcpclient.cpp udpclient.cpp )
#tcpclient.cpp
target_link_libraries(wtelnet iow wlog wflow)

