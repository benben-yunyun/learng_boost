#include <iostream>
#include <vector>

#include <boost/pool/pool_alloc.hpp>


int main() {
  std::vector<int,boost::pool_allocator<int>> v;
  v.push_back(1);
  std::cout << "[INFO] v.size() = " << v.size() << std::endl;
  return 0;
}
