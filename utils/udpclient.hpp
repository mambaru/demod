#pragma once

#include <memory>
#include <boost/asio.hpp>
#include <functional>

class udpclient
{
  class impl;
public:
  void start( boost::asio::io_service& io, std::string addr, std::string port, std::function<void(std::string)> h);
  void send(const std::string& data);
private:
  std::shared_ptr<impl> _impl;
};
