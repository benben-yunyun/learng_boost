#include <iostream>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

void test_time_duration() {
  std::cout << "[INFO] test time duration begin" << std::endl;
  boost::posix_time::time_duration td = boost::posix_time::hours(1) + 
    boost::posix_time::minutes(1) + 
    boost::posix_time::seconds(1) + 
    boost::posix_time::millisec(1);
  std::cout << "total seconds: " << td.total_seconds() << std::endl;
  std::cout << "to sample string: " << boost::posix_time::to_simple_string(td) << std::endl;
  std::cout << "[INFO] test time duration end" << std::endl;
}

void test_posix_time() {
  std::cout << "[INFO] test posix time begin" << std::endl;
  boost::posix_time::ptime time(boost::gregorian::date(2002,boost::gregorian::Jan,10),
                                boost::posix_time::time_duration(1,2,3));
  boost::posix_time::ptime time2(boost::gregorian::date(2002,boost::gregorian::Jan,10),boost::posix_time::hours(1)+boost::posix_time::millisec(5));

  boost::posix_time::ptime time3(boost::posix_time::neg_infin);

  std::cout << boost::posix_time::second_clock::local_time() << std::endl;
  
}

int main(int argc, char *argv[])
{
  test_posix_time();
  test_time_duration();
  return 0;
}
