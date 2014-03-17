#include "pubsub_gateway_instance.hpp"
#include <wfc/memory.hpp>
#include <wfc/pubsub/api/method_list.hpp>
#include <wfc/jsonrpc.hpp>

namespace wfc{

pubsub_gateway_instance::~pubsub_gateway_instance()
{
  
}

pubsub_gateway_instance::pubsub_gateway_instance(const std::string& name, std::weak_ptr<global> g, const pubsub_gateway_config& conf)
  : _name(name)
  , _global(g)
  , _conf(conf)
{
  this->reconfigure(_conf);
}

void pubsub_gateway_instance::reconfigure(const pubsub_gateway_config& conf)
{
  if ( conf.enabled && !_gateways )
  {
    _gateways = std::make_shared<gateway_type>(_global, conf.gateways );
  }
  else if (conf.enabled)
  {
    _gateways.reset();
  }
  if ( _gateways )
  {
    _gateways->reconfigure(conf.gateways);
  }
  _conf = conf;
}

void pubsub_gateway_instance::initialize()
{
  if ( _gateways )
  {
    if ( auto g = _global.lock() )
    {
      if ( auto ps = g->pubsubs.lock())
      {
        if ( auto ips = ps->get( _conf.target ).lock() )
        {
          std::weak_ptr< wfc::pubsub::ipubsub > pp = ips;
          _gateways->initialize( wfc::gateway::rn::jsonrpc::make_factory< ::wfc::pubsub::method_list >(pp) );
        }
      }
    }
  }
}

void pubsub_gateway_instance::start()
{
  if ( _gateways )
  {
    _gateways->start();
  }
}

void pubsub_gateway_instance::stop()
{
  if ( _gateways )
  {
    _gateways->stop();
  }
}


}