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

class Screen{
public:
  typedef string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);


  Screen &display(ostream &os)  {
    do_display(os);
    return *this;
  }

private:
  void do_display(ostream &os) const{
    os << contents;
  }
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;
};

inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
  pos row = r * width; // compute the row location
  cursor = row + c ; // move cursor to the column within that row
  return *this; // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
  pos row = r * width; // compute row location
  return contents[row + c]; // return character at the given column
}

Screen &Screen::set(char c){
  contents[cursor] = c;
  return *this;
}
Screen &Screen::set(pos r, pos col, char ch){
  contents[r*width + col] = ch;
  return *this;
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

int main(int argc, char const *argv[]) {
  int i = 0; double d = 3.14; string s = "how now brown cow";
  Screen myScreen(5, 5, 'X');
  print(cout, i, s, 42, d, myScreen);
  return 0;
}
