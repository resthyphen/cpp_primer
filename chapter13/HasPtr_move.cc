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

  HasPtr &operator=(HasPtr &&rhs){
    if(this != &rhs){
      delete ps;
      ps = rhs.ps;
      i = rhs.i;
      rhs.ps = 0;
    }
    cout << "HasPtr &operator=(HasPtr &&rhs)" << endl;
    return *this;
  }

  HasPtr& operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps); // copy the underlying string
    delete ps; // free the old memory
    ps = newp; // copy data from rhs into this object
    i = rhs.i;
    cout << "HasPtr& operator=(const HasPtr &rhs)" << endl;
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
  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
  swap(lhs.i, rhs.i); // swap the int members
}


int main(int argc, char const *argv[]) {
  HasPtr hp;
  auto hp2 = std::move(hp);
  HasPtr hp3;
  hp3 = std::move(hp2);
  return 0;
}
