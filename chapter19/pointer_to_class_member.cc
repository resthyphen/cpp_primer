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
  Screen(pos ht, pos wd, char c): height(ht), width(wd){
    string s;
    for(size_t i = 0; i!= height; ++i)
      if(i != height - 1){
        s += string(width, c) + '\n';
      }else
        s += string(width, c);
    contents = s;

  }
  pair<pos,pos> get() const { return cursor; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);


  Screen &display(ostream &os)  {
    do_display(os);
    return *this;
  }

  // data is a static member that returns a pointer to member
  static const string Screen::*data(){
    return &Screen::contents;
  }

  Screen& home(){
    cursor = {0,0};
    return *this;
  } // cursor movement functions
  Screen& forward(){
    cursor = {cursor.first + 1, cursor.second};
    return *this;
  }
  Screen& back(){
    cursor = {cursor.first - 1, cursor.second};
    return *this;
  }
  Screen& up(){
    cursor = {cursor.first , cursor.second + 1};
    return *this;
  }
  Screen& down(){
    cursor = {cursor.first , cursor.second - 1};
    return *this;
  }

  using Action = Screen& (Screen::*)();
  enum Directions { HOME, FORWARD, BACK, UP, DOWN };
  Screen& move(Directions);
private:
  void do_display(ostream &os) const{
    os << contents;
  }
  pair<pos, pos> cursor = {0,0};
  pos height = 0, width = 0;
  string contents;
  static const char bkground;
  static Action Menu[];             // function table
};

const char Screen::bkground = 'c';

inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
  cursor = {r,c};
  return *this;
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
  pos row = r * width; // compute row location
  return contents[row + c]; // return character at the given column
}

Screen &Screen::set(char c){

  pos row = cursor.first * width;
  contents[row + cursor.second] = c;
  return *this;
}
Screen &Screen::set(pos r, pos col, char ch){
  cursor = {r, col};
  contents[r*width + col] = ch;
  return *this;
}

Screen& Screen::move(Directions cm){
// run the element indexed by cm on this object
  return (this->*Menu[cm])(); // Menu[cm] points to a member function
}

Screen::Action Screen::Menu[] = { &Screen::home,
                                  &Screen::forward,
                                  &Screen::back,
                                  &Screen::up,
                                  &Screen::down
};

int main(int argc, char const *argv[]) {
  Screen myScreen(5, 5, 'X'), *pScreen = &myScreen;
  //cout << myScreen.contents << endl;
  const string Screen::*pdata = Screen::data();
  auto s = myScreen.*pdata;
  s = pScreen->*pdata;
  cout << s << endl;
  // pmf is a pointer that can point to a Screen member function that is const
  // that returns a char and takes no arguments
  pair<Screen::pos, Screen::pos> (Screen::*pmf)() const;
  pmf = &Screen::get;
  char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
  pmf2 = &Screen::get;
  // call the function to which pmf points on the object to which pScreen points
  pair<Screen::pos, Screen::pos> c1 = (pScreen->*pmf)();
  // passes the arguments 0, 0 to the two-parameter version of get on the object myScreen
  char c2 = (myScreen.*pmf2)(0, 0);
  cout << "("<< c1.first << "," << c1.second << ")" << endl;
  cout << c2 << endl;
  // Action is a type that can point to a member function of Screen
  // that returns a char and takes two pos arguments
  using Action =          //type Aliase
  char (Screen::*)(Screen::pos, Screen::pos) const;
  Action get = &Screen::get; // get points to the get member of Screen
  char c3 = (myScreen.*get)(3,4);
  cout << c3 << endl;
  myScreen.move(4,3);
  myScreen.move(Screen::HOME);
  myScreen.move(Screen::DOWN);
  c1 = (pScreen->*pmf)();
  cout << "("<< c1.first << "," << c1.second << ")" << endl;
  return 0;
}
