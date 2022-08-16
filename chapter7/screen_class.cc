#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;

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
  static const char bkground;
};

const char Screen::bkground = 'c';

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
  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
