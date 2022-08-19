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

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) { }


  ~HasPtr(){
    delete ps;
  }

private:
  string *ps;
  int i;
};

HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
  HasPtr ret = hp; // copies the given HasPtr
  // process ret
  return ret; // ret and hp are destroyed
}

class Foo {
public:
  Foo() = default;
  Foo(const Foo&){
    cout << "Foo(const Foo&)" << endl;
  }
};



int main(int argc, char const *argv[]) {
  Foo x;
  Foo y(x);
  int i = 42;
  int j = i;
  j = 0;
  cout << i << endl;
  cout << j << endl;
  return 0;
}
