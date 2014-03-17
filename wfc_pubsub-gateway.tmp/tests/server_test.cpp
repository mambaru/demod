#include "domain/hub.hpp"
#include "hub_instance.hpp"
#include <wfc/system/system.hpp>
#include <atomic>
#include <chrono>
#include <thread>

using namespace ::wfc;

void test_subscribe(std::string channel, hub& test_hub, std::atomic<int>& counter, std::atomic<int>& counter_result)
{
  request::subscribe s;
  s.channel = channel;

  test_hub.subscribe(
    
    ipubsub::request_subscribe_ptr(new request::subscribe(s) ),
                     
    [&counter](ipubsub::request_publish_ptr /*req*/, ipubsub::publish_callback callback)
    {
      if ( callback != nullptr )
        abort();
      ++counter;
      return callback_status::ready;
    },
    
    [&counter_result](ipubsub::response_subscribe_ptr resp)
    {
      if ( resp->status == pubsub_status::ready )
        ++counter_result;
      else
        abort();
      return callback_status::ready;
    }
  );
}



void test_publish(std::string channel, hub& test_hub, std::atomic<int>& /*counter*/, std::atomic<int>& counter_result)
{
  request::publish m;
  m.channel = channel;
  m.lifetime = 1000;
  m.limit = 1000;
  m.content.reserve(1000);
  std::fill_n(std::back_inserter(m.content), 1000, '1');
  //m.str("0123456789");

  test_hub.publish(
    ipubsub::request_publish_ptr(new request::publish(m) ),
    [&counter_result](ipubsub::response_publish_ptr resp)
    {
      if ( resp->status == pubsub_status::ready )
        ++counter_result;
      return callback_status::ready;
    }
  );

}



int test1()
{
  hub test_hub;
  std::atomic<int> counter1(0);
  std::atomic<int> counter1_result(0);
  std::atomic<int> counter2(0);
  std::atomic<int> counter2_result(0);

  test_publish("test.channel1", test_hub, counter1, counter1_result); // ++counter1_result
  test_publish("test.channel2", test_hub, counter2, counter2_result); // ++counter2_result

  test_subscribe("test.channel1", test_hub, counter1, counter1_result); // ++counter1_result
  test_subscribe("test.channel2", test_hub, counter2, counter2_result); // ++counter2_result

  test_publish("test.channel1", test_hub, counter1, counter1_result); // ++counter1_result, ++counter1
  test_publish("test.channel2", test_hub, counter2, counter2_result); // ++counter2_result, ++counter2

  test_publish("test.channel1", test_hub, counter1, counter1_result); // ++counter1_result, ++counter1

  std::cout << "counter1 " << counter1 << std::endl;
  std::cout << "counter2 " << counter2 << std::endl;
  std::cout << "counter1_result " << counter1_result << std::endl;
  std::cout << "counter2_result " << counter2_result << std::endl;
  
  return (
       counter1==2
    && counter1_result==4
    && counter2==1
    && counter2_result==3
  ) ? 0 : 1;
}

int test2()
{
  hub test_hub;
  std::atomic<int> pub_counter1(0);
  std::atomic<int> pub_counter1_result(0);
  std::atomic<int> pub_counter2(0);
  std::atomic<int> pub_counter2_result(0);

  std::atomic<int> sub_counter1(0);
  std::atomic<int> sub_counter1_result(0);
  std::atomic<int> sub_counter2(0);
  std::atomic<int> sub_counter2_result(0);
  std::atomic<bool> running(true);

  constexpr int MAX_COUNT = 100000;

  std::atomic<bool> subs(false);
  std::thread th1([&](){
    for (;sub_counter1!=MAX_COUNT;)
    {
      if ( subs ) continue;
      test_publish("test.channel1", test_hub, pub_counter1, pub_counter1_result);
    }
  });

  std::thread th2([&](){
    for (;sub_counter2!=MAX_COUNT;)
    {
      if ( subs ) continue;
      test_publish("test.channel2", test_hub, pub_counter2, pub_counter2_result);
    }
  });

  usleep(100000);

  auto start = std::chrono::high_resolution_clock::now();
  subs = true;
  test_subscribe("test.channel1", test_hub, sub_counter1, sub_counter1_result); // ++counter1_result
  test_subscribe("test.channel2", test_hub, sub_counter2, sub_counter2_result); // ++counter2_result
  subs = false;

  th1.join();
  th2.join();
  auto finish = std::chrono::high_resolution_clock::now();

  long int ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

  std::cout << "milliseconds " << ms << std::endl;
  std::cout << "persec " << (MAX_COUNT*2L*1000L)/(ms) << std::endl;
  std::cout << "size1 " << test_hub.topic_size("test.channel1") << std::endl;
  std::cout << "size2 " << test_hub.topic_size("test.channel2") << std::endl;

  std::cout << "pub_counter1 " << pub_counter1 << std::endl;
  std::cout << "pub_counter2 " << pub_counter2 << std::endl;
  std::cout << "pub_counter1_result " << pub_counter1_result << std::endl;
  std::cout << "pub_counter2_result " << pub_counter2_result << std::endl;
  std::cout << "sub_counter1 " << sub_counter1 << std::endl;
  std::cout << "sub_counter2 " << sub_counter2 << std::endl;
  std::cout << "sub_counter1_result " << sub_counter1_result << std::endl;
  std::cout << "sub_counter2_result " << sub_counter2_result << std::endl;

  return (
       pub_counter1==0
    && pub_counter1_result >= MAX_COUNT
    && pub_counter2==0
    && pub_counter2_result >= MAX_COUNT
    && sub_counter1==MAX_COUNT
    && sub_counter1_result==1
    && sub_counter2==MAX_COUNT
    && sub_counter2_result==1
  ) ? 0 : 1;

  
}
  
int main()
{
  return test1() + test2();
}