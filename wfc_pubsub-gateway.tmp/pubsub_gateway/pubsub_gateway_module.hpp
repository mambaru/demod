#pragma once


#include <wfc/module/multi_instance.hpp>
#include "pubsub_gateway_instance.hpp"
#include "pubsub_gateway_config_json.hpp"
#include "build_info.h"

namespace wfc{

class pubsub_gateway_module
  : public multi_instance<pubsub_gateway_build_info, pubsub_gateway_config_json::type, pubsub_gateway_instance>
{
  
};

}