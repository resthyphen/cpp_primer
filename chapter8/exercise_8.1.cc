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

istream  &func(istream &is) {
  //string s;
  char c;
  while (is >> c) {
    cout << c;
  }
  cout << endl;
  return is;
}

int main(int argc, char const *argv[]) {
  func(cin);
  return 0;
}
