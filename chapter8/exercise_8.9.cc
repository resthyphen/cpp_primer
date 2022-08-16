#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::istringstream;

istream  &func(istream &is) {
  string s;
  while (is >> s) {
    cout << s;
  }
  cout << endl;
  return is;
}

int main(int argc, char const *argv[]) {
  string s;
  while (cin >> s) {
    istringstream input(s);
    func(input);
  }
  return 0;
}
