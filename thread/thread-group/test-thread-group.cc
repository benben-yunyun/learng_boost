#include <iostream>
#include <unistd.h>
#include <cassert>


#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
/*
  thread库使用thread_group管理一组线程。内部使用std::list<thread*>来容纳thread对象
  class thread_group : private noncopyable {
  public:
  template <typename F>
  thread * create_thread(F threadfunc);
  void add_thread(thread * thrd);
  void remove_thread(thread * thrd);
  void join_all();
  void interrupt_all();
  int size() const;
  }
 */

boost::mutex io_mu;

void printing(int &x , const std::string str) {
  for (int i = 0; i < 5; ++ i) {
    boost::mutex::scoped_lock(io_mu);
    std::cout << str << "\t" << ++x << std::endl;
    boost::this_thread::sleep(boost::posix_time::seconds(2));
  }
}

void test_thread_group() {
  int x = 0;
  boost::thread_group tg;
  tg.create_thread(boost::bind(printing,boost::ref(x),"boost"));
  tg.create_thread(boost::bind(printing,boost::ref(x),"c++"));
  tg.join_all();
}

int main(int argc, char *argv[])
{
  test_thread_group();
  return 0;
}
