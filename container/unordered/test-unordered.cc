#include <iostream>

#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
/*
  template <
  typename Key,
  typenmae Hash = boost::hash<Key>,
  typename Pred = boost::equal_to<Key>,
  typename Alloc = std::allocator<Key> >
  class unordered_set;

  template <
  typename Key,
  typename Hash = boost::hash<Key>,
  typename Pred = boost::equal_to<Key>,
  typename Alloc = std::allocator<Key> >
  class unordered_multiset;
 */
void test_unordered_set() {
  std::cout << "[INFO] test unordered set begin" << std::endl;
  boost::unordered_set<int> s = (boost::assign::list_of(1),2,3,4,5);
  for ( boost::unordered_set<int>::iterator iter = s.begin();
        iter != s.end();
        ++ iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
  std::cout << s.size() << std::endl;
  
  s.clear();
  std::cout << s.empty() << std::endl;
  s.insert(8);
  s.insert(45);
  std::cout << s.size() << std::endl;
  std::cout << *s.find(8) << std::endl;
}

/*
  tempalte <
  typename Key, typename Mapped,
  typename Hash = hash<Key>,
  typename Pred = std::equal_to<Key>,
  typename Alloc = std::allocator<Key> >
  class unordered_map;
  >
 */
void test_unordered_map() {
  std::cout << "[INFO] test unordered map begin" << std::endl;
  boost::unordered_map<int, std::string> um = boost::assign::map_list_of(1,"one")  (2,"two")  (3,"three");
  
  um.insert(std::make_pair(10,"ten"));
  std::cout << um[10] << std::endl;
  um[11] = "eleven";
  um[15] = "fifth";
  
  for(BOOST_AUTO(p,um.begin());p!=um.end();++p) {
    std::cout << p->first << "-" << p->second << ",";
  }
  std::cout << std::endl;
  um.erase(11);
  std::cout << um.size() << std::endl;
}

int main(int argc, char *argv[])
{
  test_unordered_set();
  test_unordered_map();
  return 0;
}
