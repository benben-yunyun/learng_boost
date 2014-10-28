#include <iostream>
#include <cassert>
#include <exception>

#include <boost/exception/all.hpp>


// c++ std::exception 使用方法
// class my_exception : public std::exception {
// private:
//   int err_no;
// public:
//   my_exception(const char * msg, int err) : 
//     std::exception(std::string(msg)),err_no(err){
//   }
//   int get_err_no() {
//     return err_no;
//   }
// };


/*
  boost::eception 类摘要
  class exception {
  protect:
  exception();
  exception( exception const & x);
  ~exception();
  template<class E, class Tag, class T>
  private:
  friend E const & operator<<(E const &,error_info<Tag,T> const &); // 将error_info存储
  };
  template<class ErrorInfo,class E>
  typename ErrorInfo::error_info::value_type * get_error_info(E &x); // 得到error_info信息


  // Tag 一般是一个空类，用来生成不同的异常类
  // T 为实际存储的exception info类型
  template <class Tag, class T> 
  class error_info {
  public:
  typedef T value_type;
  
  error_info(value_type const & v);
  value_type & value();

  }

*/

class my_exception2 :
  virtual public std::exception,
  virtual public boost::exception {};

// struct tag_err_no{};
// struct tag_err_str{};

typedef boost::error_info<struct tag_err_no, int> err_no;
//boost::DEFINE_ERROR_INFO(std::string,err_str);
typedef boost::error_info<struct tag_err_str, std::string> err_str;


void test_exception() {
  try {
    try {
      throw my_exception2() << err_no(10);
    } catch (my_exception2 &e) {
      std::cout << *boost::get_error_info<err_no>(e) << std::endl;
      std::cout << e.what() << std::endl;
      e << err_str("other info") 
        << boost::throw_file(__FILE__) 
        << boost::throw_function(BOOST_CURRENT_FUNCTION)
        << boost::throw_line(__LINE__);
      throw;
    }
  }
  catch (my_exception2 & e) {
    std::cout << *boost::get_error_info<err_str>(e) 
              << *boost::get_error_info<boost::throw_file>(e)
              << *boost::get_error_info<boost::throw_function>(e)
              << *boost::get_error_info<boost::throw_line>(e)
              << std::endl;
  }

}

struct my_exception3 {};
void test_enable_error_info() {
  try {
    throw boost::enable_error_info(my_exception3()) << err_no(10);
  }
  catch (boost::exception& e) {
    std::cout << *boost::get_error_info<err_no>(e) << std::endl;
  }
}

int main(int argc, char *argv[])
{
  test_enable_error_info();
  return 0;
}
