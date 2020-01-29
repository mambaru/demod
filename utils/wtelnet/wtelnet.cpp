#include "tcpclient.hpp"
#include "udpclient.hpp"
#include <wlog/init.hpp>
#include <iostream>
#include <thread>
#include <condition_variable>
#include <atomic>

namespace 
{
int batch = 1;
bool run  = true;
std::atomic<int> count; 
std::condition_variable cv;
std::mutex cv_m; 

void handler( const std::string& str);

template<typename H>
void cin_thread(std::shared_ptr<H> cli)
{
  std::string str;
  while ( run && !std::cin.eof() )
  {
    std::unique_lock<std::mutex> lk(cv_m);
    cv.wait(lk, []
    {
      return count < batch && run;
    });
    std::cin >> str;
    if ( str.empty() )
      continue;
    if ( std::cin.eof() )
      break;
    ++count;
    cli->send(str);
    str.clear();
  }
  
  std::unique_lock<std::mutex> lk(cv_m);
  
  cv.wait(lk, []
  {
  
    return count == 0 && run;
  });
  
  cli->stop();
}


void handler( const std::string& str)
{
  --count;
  std::cout << str << std::endl;
  cv.notify_all();
}

}

int main(int argc, char* argv[])
{
  if ( argc < 4 )
  {
    std::cout << "usage: " << std::endl;
    std::cout << "\twtelnet protocol addr port [batch]"<< std::endl;
    std::cout << "\twtelnet tcp 0.0.0.0 12345"<< std::endl;
    std::cout << "\twtelnet udp 0.0.0.0 12345 1"<< std::endl;
    std::cout << "\twtelnet udp 0.0.0.0 12345 100"<< std::endl;
    return -1;
  }
  else if (argc > 4)
  {
    batch = std::atoi(argv[4]);
    if ( batch == 0)
      batch = 1;
  }
  
  std::thread thread;
  wlog::disable();
  boost::asio::io_service ios;
  using namespace std::placeholders;
  if ( std::string(argv[1]) == "tcp")
  {
    std::cout << "IP4/TCP BATCH=" << batch << std::endl;
    auto tcp = std::make_shared<tcpclient>();
    tcp->start(ios, argv[2], argv[3], handler );
    thread = std::thread( std::bind(cin_thread<tcpclient>, tcp) );
  }
  else if ( std::string(argv[1]) == "udp")
  {
    std::cout << "IP4/UDP BATCH=" << batch << std::endl;
    auto udp = std::make_shared<udpclient>();
    udp->start(ios, argv[2], argv[3], handler );
    thread = std::thread( std::bind(cin_thread<udpclient>, udp) );
  }
  else
  {
    std::cout << "Enter tcp or udp protocol." << std::endl;
  }
  
  ios.run();
  std::cout << "Done!" << std::endl;
  run = false;
  //std::cin.close();
  thread.join();
  std::cout << "bye!" << std::endl;
}
