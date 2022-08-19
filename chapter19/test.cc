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

void *operator new(size_t size){
  cout << "overloading new" << endl;
  if (void *mem = malloc(size))
    return mem;
  else
    throw bad_alloc();
}

void operator delete(void *mem) noexcept {
  cout << "overloading delete" << endl;
  free(mem);
}

class A {
public:
  virtual ~A() = default;
};
class B : public A {
 };
class C : public B { /* . . . */ };
class D : public B, public A { /* . . .*/ };

int main(int argc, char const *argv[]) {
  int height = 3;
  int width = 3;
  int arr[height][width];
  cout << arr[2][2] << endl;
  string s;
  for(size_t i = 0; i!= height; ++i)
    if(i != height - 1){
      s += string(width, 'x') + '\n';
    }else
      s += string(width, 'x');
  cout << s << endl;
  string s2("abc\ndef\nghi");
  cout << s2.size() << endl;
  cout << s2[7] << endl;
  return 0;
}
