#include "udpclient.hpp"
#include <functional>
#include <iow/ip/udp/client/client.hpp>
#include <iow/io/basic/aspect.hpp>



//typedef iow::io::basic::aspect<std::mutex> aspect;


class udpclient::impl
  : public iow::ip::udp::client::client<>
{
public:
  typedef iow::ip::udp::client::client<> super;
  impl(boost::asio::io_service& io): super(io) {};
};

void udpclient::start(boost::asio::io_service& io, std::string addr, std::string port, std::function<void(std::string)> h)
{
  _impl = std::make_shared<impl>(io);
  iow::ip::udp::client::options opt;
  opt.addr = addr;
  opt.port = port;
  opt.connection.reader.sep = "\r\n";
  opt.connection.writer.sep = "\r\n";
  
  
  std::function<void(iow::io::data_ptr)> handler = [h](iow::io::data_ptr d)
  {
    if ( d == nullptr )
      h("");
    else
      h(std::string(d->begin(), d->end()));
  };
  
  using namespace std::placeholders;
  opt.connection.input_handler = std::bind(handler, _1);
  _impl->start(opt);
}

void udpclient::send(const std::string& d)
{
  _impl->send( std::make_unique<iow::io::data_type>(d.begin(), d.end()) );
}

void udpclient::stop()
{
  _impl->stop();
}

