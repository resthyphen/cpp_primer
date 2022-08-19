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

class HasPtr{
public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0), use(new std::size_t(1)){}

  HasPtr(const HasPtr &p):
    ps(p.ps), i(p.i), use(p.use) { ++*use; }

  HasPtr& operator=(const HasPtr &rhs);
  ~HasPtr();

  string*& get(){    // return a reference to pointer ps
    return ps;
  }


private:
  string *ps;
  int i;
  size_t *use;
};

HasPtr::~HasPtr()
{
  if (--*use == 0){ // if the reference count goes to 0
    delete ps; // delete the string
    delete use; // and the counter
  }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
  ++*rhs.use; // increment the use count of the right-hand operand
  if (--*use == 0) { // then decrement this object's counter
    delete ps; // if no other users
    delete use; // free this object's allocated members
  }
  ps = rhs.ps; // copy data from rhs into this object
  i = rhs.i;
  use = rhs.use;
  return *this; // return this object
}

int main(int argc, char const *argv[]) {
  HasPtr hp1("hello");
  HasPtr hp2 = hp1;
  (*hp2.get())[1] = 'a';
  cout << *hp1.get() << endl;
  string s = "hi";
  cout << ('"' + s + '"') << endl;
  return 0;
}
