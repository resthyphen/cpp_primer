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
using std::allocator;
using std::plus;
using std::begin;
using std::end;
using std::ostringstream;

// print any type we don't otherwise handle
template <typename T> string debug_rep(const T &t){
  cout << "debug_rep(const T &t)" << endl;
  ostringstream ret;      // see § 8.3 (p. 321)
  ret << t;             // uses T's output operator to print a representation of t
  return ret.str();   // return a copy of the string to which ret is bound
}

// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template<typename T>
ostream &print(ostream &os, const T &t){
  return os << t; // no separator after the last element in the pack
}

// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest){
  os << t << ", "; // print the first argument
  return print(os, rest...); // recursive call; print the other arguments
}

// call debug_rep on each argument in the call to print
template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest){
  // print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an)
  return print(os, debug_rep(rest)...);
}


int main(int argc, char const *argv[]) {
  string s1 = "aasie";
  string s2 = "i33okjf";
  string s3 = "hello";
  string s4 = "other";
  string s5 = "world";
  //errorMsg(cerr, s1, s2, s3, s4, s5);
  errorMsg(std::cout, 1, 2, 3, 4, 9.0f, "sss", "alan");
  return 0;
}
