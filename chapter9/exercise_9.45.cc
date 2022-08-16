#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

string &func(string &s, const string &prefix, const string &suffix){
  auto iter = s.begin();
  s.insert(iter, prefix.begin(), prefix.end());
  s.append(" " + suffix);
  return s;
}

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  func(s, "Mr.", "Jr.");
  cout << s << endl;
  return 0;
}
