#include <iostream>

#include <boost/serialization/singleton.hpp>

class test_singleton {
public:
  test_singleton() {
    std::cout << "[INFO] test_singleton start" << std::endl;
  }
  ~test_singleton() {
    std::cout << "[INFO] test_singleton end" << std::endl;
  }
  void print() const {
    std::cout << "[INFO] print" << std::endl;
  }
};

int main(int argc, char *argv[])
{
  std::cout << "[INFO] main start" << std::endl;
  typedef boost::serialization::singleton<test_singleton> a;
  a::get_const_instance().print();
  std::cout << "[INFO] main end" << std::endl;
  return 0;
}
