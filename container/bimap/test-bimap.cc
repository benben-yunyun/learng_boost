#include <iostream>



#include <boost/bimap.hpp>
#include <boost/typeof/typeof.hpp>


/*
  类摘要：
  template <typename LeftCollectionType, typename RightCollectionType> 
  class bimap
 */

void test_bimap() {
  std::cout << "[INFO] test bimap begin" << std::endl;
  boost::bimap<int,std::string> bm;
  bm.left.insert(std::make_pair(1,"111"));
  bm.left.insert(std::make_pair(2,"222"));
  
  bm.right.insert(std::make_pair("string",10));
  bm.right.insert(std::make_pair("bimap",20));
  
  for(BOOST_AUTO(pos,bm.left.begin());
      pos != bm.left.end(); ++ pos) {
    std::cout << "LEFT[" << pos->first << "]=" 
              << pos->second << std::endl;
  }
}

int main(int argc, char *argv[])
{
  test_bimap();
  return 0;
}
