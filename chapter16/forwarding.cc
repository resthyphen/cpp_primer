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

// template that takes a callable and two parameters
// and calls the given callable with the parameters ''flipped''
// flip1 is an incomplete implementation: top-level const and references are lost

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2){
  f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2){
  f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2){
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}


void f(int v1, int &v2){  // note v2 is a reference
  cout << v1 << " " << ++v2 << endl;
}

void g(int &&i, int& j){
  cout << i << " " << (j += 2) << endl;
}

int main(int argc, char const *argv[]) {
  int i = 1, j = 0;
  f(42, i);
  cout << i << endl;
  flip2(f, j, 42);
  cout << j << endl;
  flip(g, i, 42);
  cout << i << endl;
  return 0;
}
