message(STATUS "MODULE PATH: ${CMAKE_MODULE_PATH}")


include(BuildInfo)

SET(
  wfc_pubsub_gateway_source_list
  pubsub_gateway_instance.cpp
)

add_library(
  wfc_pubsub-gateway SHARED
  ${wfc_pubsub_gateway_source_list}
)

build_info(wfc_pubsub-gateway pubsub_gateway)

