#pragma once

#include <memory>
#include <boost/asio.hpp>
#include <functional>

class tcpclient
{
  class impl;
public:
  void start( boost::asio::io_service& io, std::string addr, std::string port, std::function<void(std::string)> h);
  void stop();
  void send(const std::string& data);
private:
  std::shared_ptr<impl> _impl;
};
