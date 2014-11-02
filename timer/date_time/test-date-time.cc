#include <iostream>
#include <cassert>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/greg_month.hpp>
#include <boost/date_time/gregorian/greg_weekday.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>


/*
  date_time库中的一些特殊时间概念。
  pos_infin: 正无限
  neg_infin: 负无限
  not_a_date_time: 无效时间
  min_date_time: 可表示的最小日期或时间
  max_date_time: 可表示的最大日期或时间
 */

/*
  date 为boost中的关于日期的类
 */
void test_date() {
  boost::gregorian::date d1;           // 无效的日期
  boost::gregorian::date d2(2001,1,1); // 使用年月日进行初始化
  boost::gregorian::date d3(2000,boost::gregorian::Jan,1); // 使用英文制定月份
  boost::gregorian::date d4(d2);                           // 拷贝构造函数
  
  assert(d1==boost::gregorian::date(boost::gregorian::not_a_date_time));
  assert(d2==d4);
  assert(d3<d4);

  // 同样可以从字符串初始化日期,但是必须需要使用工厂函数
  boost::gregorian::date d5 = boost::gregorian::from_string("1999-12-31");
  boost::gregorian::date d6 = boost::gregorian::from_undelimited_string("20111118");
  std::cout << "[INFO] d5:" << d5 << std::endl;
  std::cout << "[INFO] d6:" << d6 << std::endl;

  std::cout << "[INFO] day_clock::local_day() = " << boost::gregorian::day_clock::local_day() << std::endl;
  std::cout << "[INFO] day_clock::universal_day() = " << boost::gregorian::day_clock::universal_day() << std::endl;
}

void test_date_operation() {
  std::cout << "[INFO] test date operation begin" << std::endl;
  boost::gregorian::date d1(2000,1,1), d2(2008,8,8);
  std::cout << "[INFO] d2 - d1 = " << d2 - d1 << std::endl;
  assert(d1+(d2-d1)==d2);
  
  d1 += boost::gregorian::days(10);
  assert(d1.day()==11);
  d1 += boost::gregorian::month(2);
  assert(d1.month()==3&&d1.day()==11);
}

int main(int argc, char *argv[])
{
  test_date();
  return 0;
}
