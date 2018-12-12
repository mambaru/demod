#pragma once

#include <memory>
#include <boost/asio.hpp>
#include <functional>

class udpclient
{
  class impl;
public:
  void start( boost::asio::io_service& io, const std::string& addr, const std::string& port, std::function<void(std::string)> h);
  void stop();
  void send(const std::string& d);
private:
  std::shared_ptr<impl> _impl;
};
