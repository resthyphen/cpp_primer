#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <functional>
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
using std::multiset;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::exception;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::less;
using namespace std::placeholders;
//using namespace std;
using std::allocator;
using std::plus;
using std::begin;
using std::end;
using std::function;

class HasPtr {
  friend void swap(HasPtr&, HasPtr&);

public:
  HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) { }   //an (optional) string argument
  HasPtr(const HasPtr &orig): ps(new string(*orig.ps)), i(orig.i){
    cout << "HasPtr(const HasPtr &orig)" << endl;
  }

  HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
    p.ps = 0;
    cout << "HasPtr(HasPtr &&p)" << endl;
  }

  // assignment operator is both the move- and copy-assignment operator
  HasPtr& operator=(HasPtr rhs){
    cout << "Copy-and-Swap Move assignment" << endl;
    swap(*this, rhs);
    return *this; // return this object
  }

  ~HasPtr(){
    delete ps;
  }

private:
  string *ps;
  int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
  using std::swap;
  cout << "HasPtr version of swap" << endl;
  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
  swap(lhs.i, rhs.i); // swap the int members
}

class Foo{
  friend void swap(Foo &lhs, Foo &rhs);
public:
  Foo() = default;
  Foo(HasPtr p) : h(p){}
  Foo(const Foo &F) : h(F.h){}
  Foo& operator=(Foo rhs){
    swap(*this, rhs);
    return *this;
  }

  ~Foo(){}

private:
  HasPtr h;
};

inline
void swap(Foo &lhs, Foo &rhs){
  using std::swap;
  swap(lhs.h, rhs.h); // uses the HasPtr version of swap
  // swap other members of type Foo
}

int main(int argc, char const *argv[]) {
  Foo f1;
  Foo f2(HasPtr("hello"));
  f1 = f2;
  return 0;
}
