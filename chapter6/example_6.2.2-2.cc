#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c, string::size_type &occurs){
  auto ret = s.size(); // position of the first occurrence, if any
  occurs = 0; // set the occurrence count parameter
  for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
      if (ret == s.size())
        ret = i; // remember the first occurrence of c
      ++occurs; // increment the occurrence count
    }
  }
  return ret; // count is returned implicitly in occurs
}

int main(int argc, char const *argv[]) {
  string s = "hello";
  string::size_type ctr;
  cout << find_char(s, 'o', ctr) << endl;
  return 0;
}
