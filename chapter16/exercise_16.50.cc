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
#include <type_traits>
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
using std::max;
using std::remove_reference;
using std::ostringstream;

template <typename T> void f(T){
  cout << "f(T)" << endl;
}

template <typename T> void f(const T*){
  cout << "f(const T*)" << endl;
}

template <typename T> void g(T){
  cout << "g(T)" << endl;
}

template <typename T> void g(T*){
  cout << "g(T*)" << endl;
}

int main(int argc, char const *argv[]) {
  int i = 42, *p = &i;
  const int ci = 0, *p2 = &ci;
  g(42); g(p); g(ci); g(p2);
  f(42); f(p); f(ci); f(p2);
  return 0;
}
