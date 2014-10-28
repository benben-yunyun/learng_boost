#include <iostream>


#include <boost/pool/detail/singleton.hpp>

/*
  singletion类摘要：
  tempalte < typename T >
  class singleton_default {
  public:
  typedef T object_type;
  static object_type & instance();
  }

  该类保证类型T的对象在main运行之前就已创建，T必须有一个无参的构造函数。
 */

class test_singleton {
public:
  test_singelton() {
    std::cout << " create test_singleton " <<std::endl;
  }
  ~test_singleton() {
    std::cout << " desctroy test_singleton" << std::endl;
  }
};

int main(int argc, char *argv[])
{
  std::cout << " main start " << std::endl;
  boost::pool::details::singleton_default<test_singleton> a;
  std::cout <<  "main end " << std::endl;
  return 0;
}
