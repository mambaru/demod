#pragma once

#include <wfc/gateway/rn/jsonrpc/gateway_config_json.hpp>
#include "pubsub_gateway_config.hpp"
#include <wfc/json/json.hpp>
#include <wfc/json/name.hpp>

namespace wfc{

struct pubsub_gateway_config_json
{
  FAS_NAME(enabled)
  FAS_NAME(target)
  FAS_NAME(gateways)
  
  typedef json::object<
    pubsub_gateway_config,
    fas::type_list_n<
      json::member<n_enabled, pubsub_gateway_config, bool, &pubsub_gateway_config::enabled>,
      json::member<n_target,  pubsub_gateway_config, std::string, &pubsub_gateway_config::target>,
      json::member<
        n_gateways, 
        pubsub_gateway_config, 
        ::wfc::gateway::rn::jsonrpc::gateway_list_config, 
        &pubsub_gateway_config::gateways, 
        ::wfc::gateway::rn::jsonrpc::gateway_list_config_json::type
      >
    >::type
  > type;
  
  typedef type::serializer serializer; 
};

}
