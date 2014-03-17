enable_testing()

include_directories(../hub)

add_executable(hub_test hub_test.cpp)

target_link_libraries(hub_test wfc wfc_hub pthread)

add_test(hub_test hub_test)
