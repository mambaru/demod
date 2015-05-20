include(BuildInfo)

#include_directories(../wfcroot/wfc)
#include_directories(../wfcroot/iow)
#include_directories(../wfcroot/wfc_startup)
#include_directories(../wfcroot/wfc_config)
#include_directories(../wfcroot/wfc_core)
#include_directories(../wfcroot/wfc_logger)
#include_directories(../wfcroot/wfc_broker)
#include_directories(../wfcroot/wfc_hub)
#include_directories(../wfcroot/wfc_repli-hub)
#include_directories(../wfcroot/wfc_pubsub-service)
#include_directories(../wfcroot/wfc_pubsub-gateway)
#include_directories(../wfc_demo)

include_directories(..)

add_executable(demod demod.cpp )

#find_library(COMET NAMES comet PATHS ../../comet/build/comet NO_DEFAULT_PATH)

#message(STATUS ${COMET} )

#target_link_libraries(demod wfc wfc_startup wfc_core wfc_config wfc_logger wfc_hub wfc_pubsub-service demo  wfc_demo)
#add_dependencies(demod wfc wfc_startup wfc_core wfc_config wfc_logger wfc_hub wfc_pubsub-service demo wfc_demo)

SET(
  demod_lib_list
  wfcroot
  #wfc_startup 
  #wfc_core
  #wfc_config 
  #wfc_logger 
  #wfc_broker
  #wfc_hub 
  #wfc_repli-hub 
  #wfc_pubsub-service 
  #wfc_pubsub-gateway 
  #wfc_demo 
  #wfc
  #demo 
  #demo_hash
)


target_link_libraries(demod ${demod_lib_list})

add_dependencies(demod ${demod_lib_list})

build_info(demod demod)
