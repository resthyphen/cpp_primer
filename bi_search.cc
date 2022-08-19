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
#include <numeric>
#include <bitset>
#include <regex>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <typeinfo>
//#include "sales_data.h"
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
using std::make_pair;
using std::bitset;
using std::regex;
using std::smatch;
using std::regex_error;
using std::sregex_iterator;
using std::regex_iterator;
using std::cregex_iterator;
using namespace std::regex_constants;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
using std::bernoulli_distribution;
using std::noskipws;
using std::uppercase;
using std::showbase;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::right;
using std::setw;
using std::fstream;
using std::bad_alloc;
using std::bad_cast;
using std::function;
using std::mem_fn;

template<typename ITER, typename T>
ITER bi_search(ITER b, ITER e, T sought){
  auto beg = b, end = e;
  auto mid = b + (e - b)/2;

  //if(*mid == sought || mid == end || (mid - 1 - beg) < 0)
  if(beg == end)
    return mid;
  //cout << *mid << endl;
  if(sought > *mid)
    bi_search(mid + 1, end, sought);
  else if(sought < *mid)
    bi_search(beg, mid, sought);

}

/*
> 3.3
beg = 0, end = 9, mid = 4  3.3 < 5
beg = 0, end = 4, mid = 2  3.3 > 3
beg = 3, end = 4, mid = 3  3.3 < 4
beg = 3, end = 3, mid = 3  .....

> 7.5
beg = 0, end = 9, mid = 4  7.5 > 5
beg = 5, end = 9, mid = 7  7.5 < 8
beg = 5, end = 7, mid = 6  7.5 > 7 
beg = 7, end = 7, mid = 7  7.5 < 8
*/

int main(int argc, char const *argv[]) {
  vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //               0  1  2  3  4  5  6  7  8   9  10
  auto i = bi_search(v.begin(), v.end(), 3.3);
  cout << (i - v.begin()) << endl;
  i = bi_search(v.begin(), v.end(), 7.5);
  cout << (i - v.begin()) << endl;
  cout << *i << endl;
  return 0;
}
