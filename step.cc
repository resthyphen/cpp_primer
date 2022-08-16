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
#include <cmath>
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

double step(double price){   //object price
  if(price < 2.9)
    return 0.03;
  if(price > 2.9 && price < 3.1)
    return 0.1*price - 0.26;
  if(price > 3.1 && price < 4.8)
    return 0.05;
  if(price > 4.8 && price < 5.2)
    return 0.2 * price - 0.91;
  if(price > 5.2 && price < 9.7)
    return 0.13;
  if(price > 9.7 && price < 10.3)
    return 0.25 * price - 1.81;
  if(price > 10.3 && price < 19.4)
    return 0.25;
  if(price > 19.4 && price < 20.6)
    return 0.2083 * price - 3.79098;
  if(price > 20.6 && price < 48.5)
    return 0.5;
  if(price > 48.5 && price < 51.5)
    return 0.25 * price - 11.625;
  if(price > 51.5 && price < 97)
    return 1.25;
  if(price > 97 && price < 103)
    return 0.416 * price - 40.348;
  if(price > 103)
    return 2.5;
}

int main(int argc, char const *argv[]) {
  double price;
  while (true) {
    cout << "price = " ;
    cin >> price;
    cout << "step = " << step(price) << endl;
    cout << endl;
  }

  return 0;
}
