#include <iostream>

#include <boost/dynamic_bitset.hpp>
#include <boost/utility/binary.hpp>

void test_dynamic_bitset_constructor() {
  std::cout << "[INFO] test dynamic bitset constructor begin" << std::endl;
  boost::dynamic_bitset<> db1;
  boost::dynamic_bitset<> db2(10);
  boost::dynamic_bitset<> db3(0x16,BOOST_BINARY(10101));
  boost::dynamic_bitset<> db4(std::string("0100"));
  boost::dynamic_bitset<> db5(db3);
  
  boost::dynamic_bitset<> db6;
  db6 = db4;

  for ( int i = 0 ; i < db3.size() ; ++ i) {
    std::cout << db3[i] ;
  }
  std::cout << std::endl;
  std::cout << db3.to_ulong() << std::endl;
  std::cout << std::hex << db3.to_ulong() << std::endl;
  std::cout << db4[0] << db4[1] << db4[2] << std::endl;
}

int main(int argc, char *argv[])
{
  test_dynamic_bitset_constructor();
  return 0;
}
