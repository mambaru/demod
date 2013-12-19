include(BuildInfo)

include_directories(../wfc)
include_directories(../wfc_config)
include_directories(../wfc_core)
include_directories(../wfc_logger)
include_directories(../wfc_hub)
include_directories(../wfc_demo)

add_executable(demod demod.cpp )

#find_library(COMET NAMES comet PATHS ../../comet/build/comet NO_DEFAULT_PATH)

#message(STATUS ${COMET} )

target_link_libraries(demod wfc wfc_core wfc_config wfc_logger wfc_hub wfc_demo)
add_dependencies(demod wfc wfc_core wfc_config wfc_logger wfc_hub wfc_demo)
build_info(demod demod)