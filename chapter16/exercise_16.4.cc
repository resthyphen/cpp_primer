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

template <typename Iter, typename V>
Iter find_t(const Iter &i1, const Iter &i2, const V &v){
    auto iter = i1;
    while (iter != i2) {
      if(*iter == v)
        return iter;
      ++iter;
    }
    return i2;
}

int main(int argc, char const *argv[]) {
  vector<int> v{1, 2, 3, 5, 6};
  list<int> l{1, 2, 3, 5, 6};
  auto result1 = find_t(v.begin(), v.end(), 3);
  auto result2 = find_t(l.begin(), l.end(), 3);
  cout << *result1 << endl;
  return 0;
}
