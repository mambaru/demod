#include "tcpclient.hpp"
#include "udpclient.hpp"
#include <wlog/init.hpp>
#include <iostream>
#include <thread>
#include <condition_variable>

#error cat for udp block
bool run  = true;
std::atomic<int> count; 
std::condition_variable cv;
std::mutex cv_m; 

template<typename H>
void cin_thread(std::shared_ptr<H> cli)
{
  std::string str;
  std::cout << "-1-" << run << std::endl;
  while ( run && !std::cin.eof() )
  {
    std::cout << "-2-" << std::endl;
    std::unique_lock<std::mutex> lk(cv_m);
    cv.wait(lk, []{return count < 10 && run;});
    std::cout << "-2.1- " << count << std::endl;
    std::cin >> str;
    std::cout << "-2.2- " << count << std::endl;
    if ( std::cin.eof() )
      break;
    std::cout << "-2.3- send: " << str << std::endl;
    ++count;
    cli->send(str);
    str.clear();
  }
  std::cout << "-3-" << std::endl;
  std::unique_lock<std::mutex> lk(cv_m);
  std::cout << "-4-" << std::endl;
  cv.wait(lk, []{return count == 0 && run;});
  std::cout << "-5-" << std::endl;
  cli->stop();
}


void handler( std::string str)
{
  --count;
  std::cout << str << " " << count << std::endl;
  cv.notify_all();
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
  
  std::thread thread;
  wlog::disable();
  boost::asio::io_service ios;
  using namespace std::placeholders;
  if ( std::string(argv[1]) == "tcp")
  {
    std::cout << "IP4/TCP" << std::endl;
    auto tcp = std::make_shared<tcpclient>();
    tcp->start(ios, argv[2], argv[3], handler );
    thread = std::thread( std::bind(cin_thread<tcpclient>, tcp) );
  }
  else if ( std::string(argv[1]) == "udp")
  {
    std::cout << "IP4/UDP" << std::endl;
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
