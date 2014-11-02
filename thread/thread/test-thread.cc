#include <iostream>
#include <ctime>
#include <unistd.h>             // for sleep
#include <cassert>              // for assert
// #define BOOST_DATE_TIEM_SOURCE
// #define BOOST_THREAD_NO_LIB

#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
/*
  thread提供7种互斥量
  mutex 独占式互斥量
  try_mutex mutex同义词为了兼容以前版本
  timed_mutex 独占式，提供超时解锁机制
  recursive_mutex 递归式互斥变量，可以多次锁定，相应多次解锁
  recursive_try_mutex recursive_mutex 同义词，兼容以前版本
  recursive_timed_mutex 提供超市解锁的，递归式互斥变量
  shared_mutex multiple-reader/multiple-write式共享互斥变量
  
  typedef boost::posix_time::ptime system_time;

  基本借口：
  class mutex : boost::noncopyable
  {
  public:
  void lock(); // 互斥锁，阻塞性
  bool try_lock(); // 试图锁住，成功返回true，否则返回false，非阻塞
  void unlock(); // 解锁
  
  bool timed_lock(system_time const & abs_time); // 只属于timed_mutex,recursive_timed_mutex拥有，如果时间到，还不能加锁，返回false
  template <typename TimeDuration>
  bool timed_lock(TimeDuration const & relative_time);

  typedef unspecified-type scope_lock;
  typedef unspecified-type scoped_try_lock;
  };
 */
void test_mutex() {
  boost::mutex mu;
  try {
    mu.lock();
    std::cout << "some operations" << std::endl;
    mu.unlock();
  } 
  catch( ...) {
    mu.unlock();
  }
  // 使用互斥量的lock_guard类，避免上述try-catch的繁琐写法
  boost::mutex::scoped_lock lock(mu);
} 

/*
  线程thread对象
  class thread {
  public:
  thread();
  
  // 构造函数
  template <class F> explicit thread(F f);
  template <class F, class A1, class A2 ...>
  thread(F f,A1 a1, A2 a2,...);
  
  // 线程管理
  bool joinable() const;
  void join();                  // 等待线程结束，阻塞性
  bool timed_join(const system_time& wait_until);
  template <typename TimeDuration> 
  bool timed_join(TimeDuration const & rel_time);
  void detach();                // 分离，非阻塞。资源会自动释放,但是主线程解锁，就结束了。
  void interrupt();
  bool interruption_requested() const ;

  // 静态成员
  static void yield();
  static void sleep(const system_time& xt);
  static unsigned hardware_concurrency();
  
  // 支持各种比较操作
  id get_id() const;
  bool operator=(const thread& other) const;
  };
  注意：
  thread 虽然没有从boost::noncopyable继承，但是将copy&assignment构造函数都声明成私有的了，使得其无法copy&assignment
  thread 具有转移构造函数的性质，所以可以通过工厂函数构造thread
  template <typename F> 
  thread make_thread(F f) { return boost::thread(f);}
  
  创建线程：
  线程对象函数必须支持operator()操作，可以是无参的，也可以是有参的。
  有惨的是通过创建thread对象的时候构造函数传递的，调用的时候，内容进行赋值。最多支持9个参数。
 */

boost::mutex io_mu;

void print_stream(boost::atomic_int& x, const std::string& str) {
  assert(boost::this_thread::interruption_enabled());
  for (int i = 0; i < 10; ++i) {
    boost::this_thread::disable_interruption di;
    assert(!boost::this_thread::interruption_enabled());
    boost::mutex::scoped_lock(io_mu);
    std::cout << str << ++x << std::endl << std::flush;
    std::cout << boost::this_thread::interruption_requested() << std::endl;
    boost::thread::sleep(boost::get_system_time()+boost::posix_time::millisec(1000));
    boost::this_thread::interruption_point();
    boost::this_thread::restore_interruption ri(di);
    assert(boost::this_thread::interruption_enabled());
    std::cout << "can interruption" << std::endl;
    std::cout << boost::this_thread::interruption_requested() << std::endl;
    boost::this_thread::interruption_point();
  }
}

void test_thread() {
  boost::atomic_int x(0);
  // 使用bind 构造thread
  // std::cout << boost::thread(boost::bind(print_stream,boost::ref(x),"hello")).get_id();
  // function 构造thread
  boost::function<void()> f= boost::bind(print_stream,boost::ref(x),"boost");
  boost::thread t1(f);
  std::cout << t1.get_id() << std::endl;
  t1.interrupt();
  t1.join();
  std::cout << t1.hardware_concurrency() << std::endl;
}

int main(int argc, char *argv[])
{
  test_mutex();
  test_thread();
  return 0;
}
