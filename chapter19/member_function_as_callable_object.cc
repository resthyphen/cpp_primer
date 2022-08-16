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

int main(int argc, char const *argv[]) {
  vector<string> svec{"the", "quick", "red", "fox", "", "jumps"};
  //auto fp = &string::empty;
  function<bool (const string&)> fcn = &string::empty;
  auto iter = find_if(svec.begin(), svec.end(), fcn);
  cout << typeid(iter).name() << endl;
  auto n = iter - svec.begin();
  cout << n << endl;
  cout << typeid(n).name() << endl;
  unsigned int i;
  cout << typeid(i).name() << endl;

  //Using mem_fn to Generate a Callable
  auto iter2 = find_if(svec.begin(), svec.end(), mem_fn(&string::empty));
  auto f = mem_fn(&string::empty);
  cout << f(*svec.begin()) << endl;   // ok: passes a string object; f uses .* to call empty
  cout << f(&svec[4]) << endl;   // ok: passes a pointer to string; f uses .-> to call empty

  //Using bind to Generate a Callable
  // bind each string in the range to the implicit first argument to empty
  auto it = find_if(svec.begin(), svec.end(), bind(&string::empty, _1));
  auto f2 =  bind(&string::empty, _1);
  cout << f2(*svec.begin()) << endl;   // ok: argument is a string f will use .* to call empty
  cout << f2(&svec[4]) << endl;    // ok: argument is a pointer to string f will use .-> to call empty
  return 0;
}
