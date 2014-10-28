#include <iostream>
#include <cassert>

#include <boost/logic/tribool.hpp>


/*
  tribool 类摘要：
  class tribool {
  public:
  tribool(bool value);
  enum value_t { false_value, true_value, indeterminate_value } value;
  };
  bool indeterminate(tribool x); // 检测x 是否是不确定的
 */

void test_tribool() {
  std::cout << "[INFO] test tribool begin" << std::endl;
  boost::tribool tb(true);
  boost::tribool tb2(!tb);
  if (tb) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  tb2 = boost::indeterminate;
  assert(indeterminate(tb2));
  std::cout << "[INFO] tb2 == " << tb2 << std::endl;
  if (boost::indeterminate(tb2)) {
    std::cout << "indeterminate" << std::endl;
  } else {
    std::cout << "determinate" << std::endl;
  }
  if ( tb2 == boost::indeterminate ) {
    std::cout << "[INFO] indeterminate" << std::endl;
  }
  std::cout << (tb2 || true) << std::endl;
  std::cout << (tb2 && false) << std::endl;
}

int main(int argc, char *argv[])
{
  test_tribool();
  return 0;
}
