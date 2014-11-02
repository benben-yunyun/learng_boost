/*
  测试时间相关的函数；
  time.h
  
  重要的宏及结构：
  CLOCKS_PER_SEC 每秒钟的滴答数
  clock_t 滴答计数类型
  time_t 日历时间的秒计数
  
  重要数据结构：
  struct tm; 年月日时间的计数结构体

  可以使用的全部函数：


  clock_t clock(void) 返回本程序启动后所经历的时钟滴答数
  
  double difftime(time_t timer1,time_t timer0) 返回两个日历时间之差

  time_t time(time_t *timer) 返回自1970年1月1日0时以来流逝的秒数，出错返回-1
  
  time_t mktime(struct tm *timeptr) 将年月日的时间结构返回日历流逝秒数
  
  struct tm *localtime(cosnt time_t * timer); 将日历流逝秒数转为年月日的本地时间

  struct tm * gmtime(const time_t * timer) 将日历时间转为UTC的细分时间

  char * asctime(const struct tm * timer) 将日历时间转为字符串

  char * ctime(const time_t * timer) 将日历流逝秒数转为字符串

  size_t strftime(char * strDst, size_t maxsize, const char * format, const struct tm * timer) 将细分时间转格式化输出
  

*/
#include <iostream>
#include <ctime>
#include <unistd.h>
void test_time() {
  std::cout << "[INFO] test time begin" << std::endl;
  std::cout << "[INFO] CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << std::endl;
  clock_t clocks = clock();
  std::cout << "[INFO] clock() = " << clocks << std::endl;
  time_t timers = time(nullptr);
  std::cout << "[INFO] timers => time() = " << timers << std::endl;
  sleep(2);
  time_t timers2 = time(nullptr);
  std::cout << "[INFO] timers2 => time() = " << timers2 << std::endl;
  std::cout << "[INFO] difftime(timers2,timers) = " << difftime(timers2,timers) << std::endl;
  
  struct tm * ltime = localtime(&timers);
  std::cout << "[INFO] localtime(timers) = " << asctime(ltime) << std::endl;
  
  struct tm * utctime = gmtime(&timers);
  std::cout << "[INFO] gmtime(utrctime) = " << asctime(utctime) << std::endl;
  std::cout << "[INFO] mktime(timers) = "  << mktime(ltime) << std::endl;
    
  char buf[1024];
  strftime(buf,1024,"[INFO] test strftime(ltime) %I:%M%p\n",ltime);
  std::cout << buf << std::endl;
  strftime(buf,1024,"[INFO] test strftime(utctime) %I:%M%p\n",utctime);
  std::cout << buf << std::endl;
  std::cout << "[INFO] test end";
}


int main(int argc, char *argv[])
{
  test_time();
  return 0;
}
