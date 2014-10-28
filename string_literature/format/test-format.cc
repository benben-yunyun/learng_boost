#include <iostream>

#include <boost/format.hpp>

/*
  format 是一个typedef，真正实现是basic_format
  basic_format声明如下：
  template <class charT, class Traits=std::char_traits<charT> >
  class basic_format;
  typedef basic_format<char> format;
  
  template <class charT, class Traits=std::char_traits<charT> > 
  class basic_format {
  public:
  explicit basic_format(const charT * str);
  explicit basic_format(const string_t &s);
  basic_format & operator=(const basic_format& x);
  
  string_t str() const;
  size_type size() const;
  void clear();
  basic_format & parse(const string_t &);
  
  // parse the arguments through those operator :
  template<class T> basic_format & operator%(T&x);
  friend std::basic_ostream& operator<<(...);
  };
  
  typedef basic_format<char> format;
  typedef basic_format<wchar_t> wformat;

  string str(const format &);
  
  
 */

void test_format() {
  std::cout << "[INFO] test format begin" << std::endl;
  std::cout << boost::format("%s:%d+%d=%d\n") % "sum" % 1 % 2 % (1+2);
  boost::format fmt("(%1%+%2%)*%2% = %3%\n");
  fmt % 2 % 5;
  fmt % ((2+5)*5) ;
  std::cout << fmt.str() << std::endl;

  fmt.parse("%|05d|\n%| 10s|") % 2 % "hello world";
  std::cout << fmt << std::endl;
}

int main(int argc, char *argv[])
{
  test_format();
  return 0;
}
