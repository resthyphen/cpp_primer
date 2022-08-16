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

typedef string::size_type pos;
//using pos = std::string::size_type;

template <pos H, pos W> class Screen;
template<pos H, pos W> istream& operator>>(istream &is, Screen<H,W> &scr);
template<pos H, pos W> ostream& operator<<(ostream &os, Screen<H,W> &scr);
template <pos H, pos W> class Screen{
  friend istream& operator>><H,W>(istream &is, Screen<H,W> &scr);
  friend ostream& operator<<<H,W>(ostream &os, Screen<H,W> &scr);

public:
  Screen() = default;
  Screen(char c): contents(H * W, c){}
  char get() const { return contents[cursor];}
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
    os << contents << endl;
  }

  pos cursor = 0;
  string contents;
};


template <pos H, pos W> inline // we can specify inline on the definition
Screen<H,W>& Screen<H,W>::move(pos r, pos c)
{
  pos row = r * W; // compute the row location
  cursor = row + c ; // move cursor to the column within that row
  return *this; // return this object as an lvalue
}

template <pos H, pos W>
char Screen<H,W>::get(pos r, pos c) const // declared as inline in the class
{
  pos row = r * W; // compute row location
  return contents[row + c]; // return character at the given column
}

template <pos H, pos W>
Screen<H,W> &Screen<H,W>::set(char c){
  contents[cursor] = c;
  return *this;
}

template <pos H, pos W>
Screen<H,W> &Screen<H,W>::set(pos r, pos col, char ch){
  contents[r * W + col] = ch;
  return *this;
}

template<pos H, pos W>
istream& operator>>(istream &is, Screen<H,W> &scr){
  // string s;
  // is >> s;
  // for(auto i : s)
  //   scr.set(i);
  is >> scr.contents;
  return is;
}

template<pos H, pos W>
ostream& operator<<(ostream &os, Screen<H,W> &scr){
  os << scr.contents << endl;
  return os;
}


int main(int argc, char const *argv[]) {
  // Screen<5,5> screen('x');
  // screen.display(cout);
  // screen.set(3, 6, 'a');
  // screen.display(cout);
  Screen<0,0> screen;
  cin >> screen;
  //cout << screen;
  screen.set(53, 272, 's');
  screen.display(cout);
  return 0;
}
