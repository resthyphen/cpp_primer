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
using std::tuple;
using std::make_tuple;
using std::get;
using std::tuple_size;
using std::tuple_element;

int main(int argc, char const *argv[]) {
  tuple<size_t, size_t, size_t> threeD; // all three members set to 0
  tuple<string, vector<double>, int, list<int>>
    someVal("constants", {3.14, 2.718}, 42, {0,1,2,3,4,5});
  auto item = make_tuple("0-999-78345-X", 3, 20.00);   //tuple<const char*, int, double>

  auto book = get<0>(item);       // returns the first member of item
  auto cnt = get<1>(item);        // returns the second member of item
  auto price = get<2>(item)/cnt;  // returns the last member of item

  get<2>(item) *= 0.8;
  cout << book << endl;
  cout << cnt << endl;
  cout << price << endl;
  typedef decltype(item) trans;
  size_t sz = tuple_size<trans>::value;
  tuple_element<1, trans>::type cnt2 = get<1>(item);
  cout << cnt2 << endl;
  return 0;
}
