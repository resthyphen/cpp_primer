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
#include <unordered_map>
#include <unordered_set>
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
using std::ostringstream;
using std::hash;
using std::unordered_multiset;

template <typename T> size_t count (const T v, const vector<T> &vec){
  auto i = vec.begin();
  size_t n = 0;
  while (i != vec.end()) {
    if(*i == v)
      ++n;
    ++i;
  }
  return n;
}

template<> size_t count(const char* value, const vector<const char*> &vec){
  auto i = vec.begin();
  size_t n = 0;
  while (i != vec.end()) {
    if(strcmp(*i, value) == 0)
      ++n;
    ++i;
  }
  return n;
}

int main(int argc, char const *argv[]) {
  vector<double> dv = {1.2, 3.3, 4, 4, 5.8};
  vector<int> iv{1,2, 4, 3, 2, 4, 5};
  vector<string> sv{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  vector<const char*> vcc = {"alan","alan","alan","alan","moophy"};
  cout << count(1.2, dv) << endl;
  cout << count(2, iv) << endl;
  cout << count(string("the"), sv) << endl;
  cout << count("alan", vcc) << endl;
  return 0;
}
