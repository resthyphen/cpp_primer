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
#include <utility>
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

class ShorterString {
public:
  bool operator()(const string &s1, const string &s2) const
    { return s1.size() < s2.size(); }
};

class SizeComp {
public:
  SizeComp(size_t n): sz(n) { } // parameter for each captured variable
  // call operator with the same return type, parameters, and body as the lambda
  bool operator()(const string &s) const {
    return s.size() >= sz;
  }

private:
  size_t sz; // a data member for each variable captured by value
};

int main(int argc, char const *argv[]) {

  return 0;
}
