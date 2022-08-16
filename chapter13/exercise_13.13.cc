#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::list;
using std::map;
using std::set;
using std::pair;
using std::multimap;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;

struct X {
  X() {cout << "X()" << endl;}
  X(const X&) { cout << "X(const X&)" <<endl; }
  X& operator=(const X &rhs){
    cout << "X& operator=" << endl;
    return *this;
  }

  ~X(){
    cout << "~X()" << endl;
  }
};

int main(int argc, char const *argv[]) {
  X a;
  X b(a);
  X c;
  c = a;
  cout << "a == b: " << (a==b) << endl;
  cout << "-------------------------------------------" << endl;
  shared_ptr<X> xp1 = make_shared<X>();
  shared_ptr<X> xp2(xp1);
  shared_ptr<X> xp3;
  xp3 = xp1;
  cout << "-------------------------------------------" << endl;
  auto p4 = new X;
  auto p5(p4);
  X *p6;
  p6 = p4;
  cout << "-------------------------------------------" << endl;
  //vector<X> v{a,b,c, *xp1, *xp2, *xp3, *p4, *p5, *p6};
  return 0;
}
