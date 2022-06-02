#pragma once

#include <memory>
#include <iow/asio.hpp>
#include <functional>

class tcpclient
{
  class impl;
public:
  void start( boost::asio::io_context& io, const std::string& addr, const std::string& port, std::function<void(std::string)> h);
  void stop();
  void send(const std::string& d);
private:
  std::shared_ptr<impl> _impl;
};
