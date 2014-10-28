#include <iostream>
#include <cassert>
#include <boost/pool/pool.hpp>


int main(int argc, char *argv[])
{
  boost::pool<> pl(sizeof(int));
  int * i = static_cast<int*>(pl.malloc());
  assert(pl.is_from(i));
  return 0;
}
