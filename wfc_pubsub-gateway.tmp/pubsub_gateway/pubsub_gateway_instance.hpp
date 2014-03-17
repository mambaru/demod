#pragma once


//#include "pubsub_gateway/server_tcp.hpp"
#include <wfc/gateway.hpp>
#include "pubsub_gateway_config.hpp"
#include <wfc/core/global.hpp>
#include <string>
#include <memory>

namespace wfc{
  
//class hub;
  
class pubsub_gateway_instance
{
public:
  virtual ~pubsub_gateway_instance();
  pubsub_gateway_instance(const std::string& name, std::weak_ptr<global> g, const pubsub_gateway_config& conf);
  void reconfigure(const pubsub_gateway_config& conf);
  void initialize();
  void start();
  void stop();
private:
  std::string _name;
  std::weak_ptr<global> _global;
  pubsub_gateway_config _conf;
  
  typedef ::wfc::gateway::rn::jsonrpc::gateway_list gateway_type;
  std::shared_ptr<gateway_type> _gateways;
  
};

}