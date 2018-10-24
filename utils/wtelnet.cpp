#include "tcpclient.hpp"
#include "udpclient.hpp"
#include <wlog/init.hpp>
#include <iostream>
template<typename H>
void handler( std::shared_ptr<H> cli, std::string str)
{
  std::cout << str << std::endl;
  str.clear();
  std::cin >> str;
  cli->send(str);
}

int main(int argc, char* argv[])
{
  if ( argc!=4 )
  {
    std::cout << "usage: " << std::endl;
    std::cout << "\twtelnet tcp 0.0.0.0 12345"<< std::endl;
    std::cout << "\twtelnet udp 0.0.0.0 12345"<< std::endl;
    return -1;
  }
  //wlog::disable();
  boost::asio::io_service ios;
  using namespace std::placeholders;
  if ( std::string(argv[1]) == "tcp")
  {
    auto tcp = std::make_shared<tcpclient>();
    tcp->start(ios, argv[2], argv[3], std::bind(handler<tcpclient>, tcp, _1) );
    handler(tcp, "IP4/TCP");
  }
  else if ( std::string(argv[1]) == "udp")
  {
    auto udp = std::make_shared<udpclient>();
    udp->start(ios, argv[2], argv[3], std::bind(handler<udpclient>, udp, _1) );
    handler(udp, "IP4/UDP");
  }
  else
  {
    std::cout << "Enter tcp or udp protocol." << std::endl;
  }
  
  ios.run();
  std::cout << "bye!" << std::endl;
}
