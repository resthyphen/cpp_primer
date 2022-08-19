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

string func(string &s, const string &prefix, const string &suffix){
  string newName = s;
  auto iter = newName.begin();
  //newName.insert(iter, prefix.begin(), prefix.end());
  newName.insert(1, prefix);
  newName.insert(newName.size(), " " + suffix);
  return newName;
}

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  s = func(s, "Mr.", "Jr.");
  cout << s << endl;
  return 0;
}
