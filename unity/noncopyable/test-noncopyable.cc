#include <iostream>

#include <boost/noncopyable.hpp>

class test_noncopyable : boost::noncopyable {
public:
  int x;
};

int main(int argc, char *argv[])
{
  test_noncopyable a,b;
  a = b;
  return 0;
}
