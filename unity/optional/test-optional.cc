#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>


#include <boost/optional.hpp>
#include <boost/typeof/typeof.hpp>

/*
  optional用来提供一个无效的状态，类似nullptr、vector.end()

  optional类摘要：
  template<typename T>
  class optional {
  optional(); // 创建一个空的对象
  optional(T const& v); // 构建一个已经初始化的optional，为v的值拷贝
  optional(bool condition, T v); // 根据condition的真假，使用v进行初始化
  optional& operator=(T const & rhs); // 可以是使用boost::none将对象赋为空

  T * operator->(); 
  T & operator*();
  T & get();
  T * get_ptr();
  T const & get_value_or(T const & default) const;
  bool operator!() const;
  }
 */

void test_optional() {
  std::cout << "[INFO] test optional begin" << std::endl;
  boost::optional<int> op0;
  boost::optional<int> op1(boost::none);
  assert(!op0);
  assert(op1 == op0);
  assert(op0.get_value_or(123) == 123);
  boost::optional<std::string> ops("test");
  std::cout << "[INFO] optional string = " << *ops << std::endl;

  std::vector<int> v(10);
  boost::optional<std::vector<int>&> opv(v); // optional 可以使用引用
  assert(opv);
  opv->push_back(5);
  assert(opv->size() == 11);

  opv = boost::none;            // 将optional赋为空
  assert(!opv);
}

boost::optional<double> calc(int x) {
  return boost::optional<double>(x!=0,1.0/x);
}

boost::optional<double> sqrt_op(double x) {
  return boost::optional<double>(x>0,sqrt(x));
}

void test_optional_function() {
  boost::optional<double> d = calc(10);
  if (d) {
    std::cout << "[INFO] calc(10) = " << *d << std::endl;
  } else {
    std::cout << "[INFO] calc(10) = none " << std::endl;
  }
  d = sqrt_op(-10);
  if (!d) {
    std::cout << "[INFO] sqrt_op = none " << std::endl;
  }
}

void test_optional_factory() {
  //boost::BOOST_AUTO(op,boost::make_optional<int>(5));
  boost::optional<int> op = boost::make_optional<int>(5);
  assert(*op==5);
  //boost::BOOST_AUTO(op2,boost::make_optional<double>((*op>10),1.0));
  boost::optional<double> op2 = boost::make_optional<double>((*op>10),1.0);
  assert(!op2);
}

int main(int argc, char *argv[])
{
  test_optional();
  test_optional_function();
  test_optional_factory();
  return 0;
}
