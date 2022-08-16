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

class screen{
public:
  typedef string::size_type pos;
  screen() = default;
  screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' '){}
  screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){}
  char get() const{
    return constents[cursor];
  }
  inline char get(pos ht, pos wd) const;
  screen &move(pos r, pos c);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents = " ";
};
