#include <iostream>
#include <sstream>
#include <boost/lexical_cast.hpp>

void test_boost_lexical_cast() {
  std::cout << "test_boost_lexical_cast begin" << std::endl;
  int x = boost::lexical_cast<int>("100");
  long y = boost::lexical_cast<long>("1000");
  float pai = boost::lexical_cast<float>("3.14e10");
  double e = boost::lexical_cast<double>("3.14");
  std::cout << x << "\t" << y << "\t" << pai << "\t" << e << std::endl;
  
  std::string str = boost::lexical_cast<std::string>(456);
  std::cout << str << std::endl;
  std::cout << boost::lexical_cast<std::string>(0.16) << std::endl;
  std::cout << boost::lexical_cast<std::string>(0x10) << std::endl;
  
  std::cout << boost::lexical_cast<bool>("1") << std::endl;
  std::cout << boost::lexical_cast<bool>("0") << std::endl;
  std::cout << "test_boost_lexical_cast end" << std::endl;
}

void test_string_stream() {
  std::stringstream cast_stream;
  cast_stream << 1000L;
  long i ;
  cast_stream >> i;
  std::cout << "[INFO] test_string_stream begin" << std::endl;
  std::cout << i << std::endl;
}

void test_bad_lexical_cast() {
  try {
    int i = boost::lexical_cast<int>("helloworld");
  }
  catch( boost::bad_lexical_cast& e) {
    std::cout << e.what() << std::endl;
  }
}

int main(int argc, char *argv[])
{
  test_boost_lexical_cast();
  test_string_stream();
  test_bad_lexical_cast();
  return 0;
}
