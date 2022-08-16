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

  // data is a static member that returns a pointer to member
  static const string Screen::*data(){
    return &Screen::contents;
  }


  Screen &display(ostream &os)  {
    do_display(os);
    return *this;
  }

  using Amove = Screen& (Screen::*)(pos, pos);
  using Aset1 = Screen& (Screen::*)(char);
  using Aset2 = Screen& (Screen::*)(pos, pos, char);
  using Adisplay = Screen& (Screen::*)(ostream&);

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

int main(int argc, char const *argv[]) {
  Screen myScreen(5, 5, 'X'), *pScreen = &myScreen;
  //cout << myScreen.contents << endl;
  const string Screen::*pdata = Screen::data();
  auto s = myScreen.*pdata;
  s = pScreen->*pdata;
  cout << s << endl;
  // pmf is a pointer that can point to a Screen member function that is const
  // that returns a char and takes no arguments
  char (Screen::*pmf)() const;
  pmf = &Screen::get;
  char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
  pmf2 = &Screen::get;
  // call the function to which pmf points on the object to which pScreen points
  char c1 = (pScreen->*pmf)();
  // passes the arguments 0, 0 to the two-parameter version of get on the object myScreen
  char c2 = (myScreen.*pmf2)(0, 0);
  cout << c1 << endl;
  cout << c2 << endl;
  // Action is a type that can point to a member function of Screen
  // that returns a char and takes two pos arguments
  using Action =
  char (Screen::*)(Screen::pos, Screen::pos) const;
  Action get = &Screen::get; // get points to the get member of Screen
  char c3 = (myScreen.*get)(3,4);
  cout << c3 << endl;
  return 0;
}
