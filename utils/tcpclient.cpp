#include "tcpclient.hpp"
#include <functional>
#include <iow/ip/tcp/client/client.hpp>


class tcpclient::impl
  : public iow::ip::tcp::client::client<> 
{
public:
  typedef iow::ip::tcp::client::client<> self;
  impl(boost::asio::io_service& io): self(io) {};
};

void tcpclient::start(boost::asio::io_service& io, std::string addr, std::string port, std::function<void(std::string)> h)
{
  _impl = std::make_shared<impl>(io);
  iow::ip::tcp::client::options opt;
  opt.addr = addr;
  opt.port = port;
  opt.async_connect = false;
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
  _impl->connect(opt);
}

void tcpclient::send(const std::string& d)
{
  _impl->send( std::make_unique<iow::io::data_type>(d.begin(), d.end()) );
}

void tcpclient::stop()
{
  _impl->close();
  _impl->stop();
}

