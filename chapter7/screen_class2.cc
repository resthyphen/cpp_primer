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

private:
  void do_display(ostream &os) const{
    os << contents;
  }
  pair<pos, pos> cursor = {0,0};
  pos height = 0, width = 0;
  string contents;
  static const char bkground;
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

int main(int argc, char const *argv[]) {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(cout);
  cout << "\n" << endl;
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
