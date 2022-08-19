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

void func(string &s, const string &oldVal, const string &newVal){
  string::size_type pos = 0;
  while(pos != s.size()){
    auto temp = pos;
    string::size_type p = 0;
    while(p != oldVal.size()){
      if(s[temp] != oldVal[p])
        break;
      ++p;
      ++temp;
    }
    if(p == oldVal.size()){
      s.replace(pos, oldVal.size(), newVal);
      pos += newVal.size();
    }else
      ++pos;
  }
}

void replaceStr(string &s, const string &oldVal, const string &newVal) {
  // Use `<` operator, because it is possible that `pos` jumps over the end
  for (std::string::size_type pos = 0; pos < s.size(); ) {
    if (s.substr(pos, oldVal.size()) == oldVal) {
        s.replace(pos, oldVal.size(), newVal);
        pos += newVal.size();
    } else
      ++pos;
  }
}

int main(int argc, char const *argv[]) {
  string oldVal = "tho";
  string newVal = "though";
  string s;
  getline(cin, s);
  cout << s << endl;
  func(s, oldVal, newVal);
  func(s, "thru", "through");
  cout << s << endl;
  return 0;
}
