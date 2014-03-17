#pragma once

#include <wfc/gateway/rn/jsonrpc/gateway_config.hpp>

namespace wfc{

struct pubsub_gateway_config
{
  bool enabled = true;
  std::string target;
  ::wfc::gateway::rn::jsonrpc::gateway_list_config gateways;
};

}
