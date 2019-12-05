project(wtelnet)

include(FindThreads)
find_package(Boost COMPONENTS system REQUIRED)

add_executable(wtelnet wtelnet.cpp tcpclient.cpp udpclient.cpp )
wci_utils(wtelnet)
target_link_libraries(wtelnet PUBLIC iow wlog wflow ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} )

