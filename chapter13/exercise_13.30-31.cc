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
  HasPtr(const HasPtr &orig): ps(new string(*orig.ps)), i(orig.i){}

  HasPtr& operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps); // copy the underlying string
    delete ps; // free the old memory
    ps = newp; // copy data from rhs into this object
    i = rhs.i;
    return *this; // return this object
  }

  bool operator<(const HasPtr &rhs) const{
    return *ps < *rhs.ps;
  }

  ~HasPtr(){
    delete ps;
  }

  const string &get() const{
    return *ps;
  }


private:
  string *ps;
  int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  cout << "have been swaped" << endl;
}



int main(int argc, char const *argv[]) {
  //string s1 = "hello";
  //string s2 = "world";
  HasPtr h1("hello");
  HasPtr h2("world");
  cout << "h1: " << h1.get() << endl;
  cout << "h2: " << h2.get() << endl;
  swap(h1, h2);
  cout << "h1: " << h1.get() << endl;
  cout << "h2: " << h2.get() << endl;

  vector<HasPtr> v{HasPtr("the"),HasPtr("quick"),HasPtr("red"),HasPtr("fox"),HasPtr("jumps"),HasPtr("over"),HasPtr("the"),HasPtr("slow"),HasPtr("red"), HasPtr("turtle")};
  sort(v.begin(), v.end());
  for(const auto &i : v)
    cout << i.get() << " ";
  cout << endl;
  return 0;
}
