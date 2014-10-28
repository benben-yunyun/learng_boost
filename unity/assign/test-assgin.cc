#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <random>
#include <boost/assign.hpp>


void test_assign_with_using() {
  using namespace boost::assign;
  std::vector<int> v_i;
  v_i += 1,2,3,4,5;
  assert(v_i.size()==5);
  std::copy(v_i.begin(),v_i.end(),std::ostream_iterator<int>(std::cout,"\t"));
  std::cout << std::endl;
  
  std::map<int,int> m_i;
  m_i += std::make_pair<int,int>(1,1),std::make_pair<int,int>(2,2);
  assert(m_i.size()==2);

  v_i.clear();
  boost::assign::push_back(v_i) (1) (2) (3) (4) (5);
  assert(v_i.size()==5);
  std::copy(v_i.begin(),v_i.end(),std::ostream_iterator<int>(std::cout,"\t"));
  std::cout << std::endl;
  
  std::list<int> l_i;
  boost::assign::push_front(l_i) (1) (2) (3) (4) (5);
  assert(l_i.size()==5);
  std::copy(v_i.begin(),v_i.end(),std::ostream_iterator<int>(std::cout,"\t"));
  std::cout << std::endl;
  
  std::cout << "[INFO] test assign with using" << std::endl;
}

// 初始化 list_of map_list_of pair_list_of tuple_list_of
void test_init() {
  std::cout << "[INFO] test init begin" << std::endl;
  std::vector<int> v = boost::assign::list_of(1) (2) (3) (4) (5);
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout,"\t"));
  std::cout << std::endl;
}

/*
  repeat,repeat_fun,range
 */
void test_repeat() {
  std::cout << "[INFO] test repeat begin" << std::endl;
  std::list<int> l = boost::assign::list_of(1).repeat(3,2) (3) (4) (5);
  std::multiset<int> ms;
  boost::assign::insert(ms).repeat_fun(5,&rand).repeat(3,2) , 4 , (5);
  std::copy(l.begin(),l.end(),std::ostream_iterator<int>(std::cout,"\t"));
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  test_assign_with_using();
  test_init();
  test_repeat();
  return 0;
}
