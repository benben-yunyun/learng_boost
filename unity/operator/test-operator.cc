#include <iostream>
#include <cassert>
#include <boost/operators.hpp>


/*
  equality_comparable: 要求提供==，自动提供!=
  less_than_comparabel: 要求提供<, 自动实现>,<=,>=
  addable: 要求提供+=, 可以自动提供+
  substractable: 要求提供-=, 可以自动提供-
  increamemtable: 提供前置++, 可以自动提供后置++
  decreamentable: 提供前置--, 可以自动提供后置--
  equivalent: 要求提供<, 可以自动实现==,
 */

class point : public boost::less_than_comparable<point>
{
public:
  point(int x,int y,int z):_x(x),_y(y),_z(z){}
  ~point() = default;
  friend bool operator<(const point & lhs,const point & rhs) {
    return (lhs._x<rhs._x);
  }
  int _x,_y,_z;
};

int main(int argc, char *argv[])
{
  point a(1,2,3),b(2,3,4);
  assert(a<b);
  assert(b>a);
  assert(b>=a);
  assert(a<=b);
  return 0;
}
