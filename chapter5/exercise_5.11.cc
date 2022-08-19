#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  char ch;
  unsigned spaceCnt = 0;
  unsigned tabCnt = 0;
  unsigned newlineCnt = 0;
  while (cin.get(ch)) {
    switch (ch) {
      case ' ':
        ++spaceCnt;
        break;
      case '\t':
        ++tabCnt;
        break;
      case '\n':
        ++newlineCnt;
        break;
    }
  }
  cout << "space: " << spaceCnt << '\n'
       << "tab: " << tabCnt << '\n'
       << "newline: " << newlineCnt << endl;
  return 0;
}
