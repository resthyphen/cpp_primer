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

// print any type we don't otherwise handle
template <typename T> string debug_rep(const T &t){
  cout << "debug_rep(const T &t)" << endl;
  ostringstream ret;      // see § 8.3 (p. 321)
  ret << t;             // uses T's output operator to print a representation of t
  return ret.str();   // return a copy of the string to which ret is bound
}

// print pointers as their pointer value, followed by the object to which the pointer points
// NB: this function will not work properly with char*; see § 16.3 (p. 698)
template <typename T> string debug_rep(T *p){
  ostringstream ret;
  cout << "debug_rep(T *p)" << endl;
  ret << "pointer: " << p; // print the pointer's own value
  if (p)
    ret << " " << debug_rep(*p); // print the value to which p points
  else
    ret << " null pointer"; // or indicate that the p is null
  return ret.str();   // r
}

// print strings inside double quotes
string debug_rep(const string &s){
  cout << "debug_rep(const string &s)" << endl;
  return '"' + s + '"';
}

// convert the character pointers to string and call the string version of debug_rep
string debug_rep(char *p){
  cout << "debug_rep(char *p)" << endl;
  return debug_rep(string(p));
}

string debug_rep(const char *p){
  cout << "debug_rep(const char *p)" << endl;
  return debug_rep(string(p));
}

int main(int argc, char const *argv[]) {
  //string s("hi");
  //cout << debug_rep(s) << endl;
  //cout << debug_rep(&s) << endl;
  //const char ca1[] = "A string example";
  cout << debug_rep("hi world!") << endl;
  //cout << debug_rep(ca1) << endl;
  return 0;
}
