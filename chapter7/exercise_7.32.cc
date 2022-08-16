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

class Screen;
//class Window_mgr;
class Window_mgr{
public:
  using ScreenIndex = vector<Screen>::size_type;
  void clear(ScreenIndex);
  Window_mgr();
private:
  //vector<Screen> screens{Screen(24, 80, ' ')};
  vector<Screen> screens;
};

class Screen{
friend void Window_mgr::clear(ScreenIndex);

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

Window_mgr::Window_mgr():screens{Screen(24, 80, ' ')}{}



void Window_mgr::clear(ScreenIndex i)
{
  // s is a reference to the Screen we want to clear
  Screen &s = screens[i];
  // reset the contents of that Screen to all blanks
  s.contents = string(s.height * s.width, ' ');
}

int main(int argc, char const *argv[]) {
  Window_mgr window;
  window.clear(0);
  cout << endl;
  return 0;
}
