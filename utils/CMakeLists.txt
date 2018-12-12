project(wtelnet)

include(FindThreads)
find_package(Boost COMPONENTS system REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/wfcroot/iow")
include_directories("${CMAKE_SOURCE_DIR}/wfcroot/wlog")
add_executable(wtelnet wtelnet.cpp tcpclient.cpp udpclient.cpp )
target_link_libraries(wtelnet iow wlog wflow ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} )

