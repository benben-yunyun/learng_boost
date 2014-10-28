#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstring>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

/*
  string_algo 算法命名规则：
  前缀i : 表示是大小写不敏感，否则为大小写敏感的。
  后缀copy ：表示该算法不会修改输入，返回处理后结果的拷贝，否则就是原地修改。
  后缀if：表示该算法需要一个作为判断的谓词函数对象，否则使用默认的判断准则。
 */

void test_string_algo() {
  std::cout << "[INFO] test string algo begin" << std::endl;
  std::string str("readme.txt");
  if (boost::ends_with(str,"txt")) {
    std::cout << boost::to_upper_copy(str) + " UPPER"<< std::endl;
    assert(boost::ends_with(str,"txt"));
  }
  boost::replace_first(str,"readme","followme");
  std::cout << "[INFO] replace_first of readme to followme " << str << std::endl;
  std::vector<char> v(str.begin(),str.end());
  std::vector<char> v2 = boost::to_upper_copy(
                                              boost::erase_first_copy(v,"txt"));
  for (int i = 0; i < v2.size(); ++ i) {
    std::cout << v2[i];
  }
}

/*
  大小写修改函数
  template<typename T> void to_upper(T& input);
  template<typename T> void to_lower(T& input);
 */
void test_upper_lower() {
  std::cout << "[INFO] test upper lower begin" << std::endl;
  std::string str("test string");
  std::cout << "[INFO] to_upper_copy(str) = " << boost::to_upper_copy(str) << std::endl;
  std::cout << "[INFO] str = " << str << std::endl;
  boost::to_upper(str);
  std::cout << "[INFO] after to_upper str = " << str << std::endl;
  std::cout << "[INFO] test upper lower end" << std::endl;
}

/*
  判断式：检测两个字符串之间的关系
  starts_with: 检测字符串是否以某个字符串前缀
  template <typename Range1T, typename Range2T> 
  bool starts_with(const Range1T & Input, const Range2T & Test);
  ends_with: 检测字符串是否以一个字符串后缀
  template <typename Range1T, typename Range2T> 
  bool ends_with(const Range1T & Input, const Range2T & Test);
  contains: 检测字符串包含一个字符串
  template <typename Range1T, typename Range2T> 
  bool contains(const Range1T & Input, const Range2T & Test);
  equals: 检测两个字符串是否相等
  template <typename Range1T, typename Range2T> 
  bool equals(const Range1T & Input, const Range2T & Test);
  lexicographical_compare: 根据字典序检测一个字符串是否小于另一个字符串
  template <typename Range1T, typename Range2T> 
  bool lexicographical_compare(const Range1T & Arg1, const Range2T & Arg2);
  all：检测一个字符串中所有字符是否满足判断函数
  template <typename Range1T, typename PredicateT> 
  bool all(const Range1T & Input, PredicateT Pred);

  除了all外所有函数都有i前缀的函数
  由于没有改变字符串的版本，所以没有copy版本
 */

void test_compare() {
  std::cout << "[INFO] test compare begin" << std::endl;
  std::string str("Power Bomb");
  assert(boost::iends_with(str,"bomb"));
  assert(!boost::ends_with(str,"bomb"));
  
  assert(boost::starts_with(str,"Power"));
  assert(boost::contains(str,"er"));
  
  std::string str2 = boost::to_lower_copy(str);
  assert(boost::iequals(str,str2));

  std::string str3("power suit");
  assert(boost::ilexicographical_compare(str,str3));
  
  assert(boost::all(str2.substr(0,5),boost::is_lower()));
  
  std::cout << "[INFO] test compare end" << std::endl;
}

/*
  判断式
  is_equal 类似equals
  is_less  比较两个对象是否具有小于关系
  is_not_greater  比较两个对象对否具有不大于关系
 */

/*
  is_space
  is_alnum
  is_alpha
  is_cntrl
  is_digit
  is_graph
  is_lower
  is_upper
  is_print
  is_punct
 */

/*
  template <typename SequenceT> 
  void trim_left(SequenceT & Input);

  template <typename SequenceT> 
  void trim_right(SequenceT & Input);

  template <typename SequenceT>
  void trim(SequenceT & Input);
 */
void test_trim() {
  std::cout << "[INFO] test_trim begin" << std::endl;
  boost::format fmt("|%s|\n");
  std::string str = "  samus aran  ";
  std::cout << fmt % boost::trim_copy(str);
  std::cout << fmt % boost::trim_left_copy(str);
  
  boost::trim_right(str);
  std::cout << fmt % str;
  
  std::string str2 = "2010 Happy New Year!!!";
  std::cout << fmt % boost::trim_left_copy_if(str2, boost::is_digit());
  std::cout << fmt % boost::trim_right_copy_if(str, boost::is_punct());
  std::cout << fmt % boost::trim_copy_if(str, boost::is_punct()||boost::is_digit()||boost::is_space());
  std::cout << "[INFO] test_trim end" << std::endl;
}



int main(int argc, char *argv[])
{
  test_upper_lower();
  test_compare();
  test_trim();
  return 0;
}
