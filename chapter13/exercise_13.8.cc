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
public:
  HasPtr(const std::string &s = std::string()):
  ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr &orig): ps(new string(*orig.ps)), i(orig.i){}

  HasPtr& operator=(const HasPtr &rhs){
    ps = new string(*rhs.ps);
    i = rhs.i;
    return *this;
  }

private:
  string *ps;
  int i;
};



int main(int argc, char const *argv[]) {

  return 0;
}
