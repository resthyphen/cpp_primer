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

// almost surely the wrong way to generate a vector of random integers
// output from this function will be the same 100 numbers on every call!
vector<unsigned> bad_randVec()
{
  static default_random_engine e;
  static uniform_int_distribution<unsigned> u(0,9);
  vector<unsigned> ret;
  for (size_t i = 0; i < 100; ++i)
    ret.push_back(u(e));
  return ret;
}

int main(int argc, char const *argv[]) {
  default_random_engine e(time(0)); // generates random unsigned integers
  for (size_t i = 0; i < 10; ++i)
    // e() "calls" the object to produce the next random number
    cout << e() << " ";
  //cout << less<int>()(1,2) << endl;
  cout << endl;
  uniform_int_distribution<unsigned> u(0,100);
  for (size_t i = 0; i < 9; ++i)
    // u uses e as a source of numbers
    // each call returns a uniformly distributed value in the specified range
    cout << u(e) << ", ";
  cout << endl;
  uniform_real_distribution<double> ru(-100,100);
  for (size_t i = 0; i < 50; ++i)
    cout << ru(e) << ", ";
  cout << endl;
  cout << "min: " << e.min() << " max: " << e.max() << endl;
  vector<unsigned> v1(bad_randVec());
  vector<unsigned> v2(bad_randVec());
  // for(auto i : v1)
  //   cout << i << " ";
  // cout << endl;
  // for(auto i : v2)
  //   cout << i << " ";
  // cout << endl;
  // cout << time(0) << endl;
  return 0;
}
