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

int main(int argc, char const *argv[]) {
  string s = "ab2c3d7R4E6";
  char c = 'a';
  string::size_type pos;
  for(; c <= 'z'; c++){
    pos = s.find_first_of(c);
    if(pos != string::npos)
      cout << c << " in the index of s is " << pos << endl;
    pos = s.find_first_of(toupper(c));
    if(pos != string::npos)
      cout << s[pos] << " in the index of s is " << pos << endl;
  }
  c = '0';
  for(; c <= '9'; c++){
    pos = s.find_first_of(c);
    if(pos != string::npos)
      cout << c << " in the index of s is " << pos << endl;
  }
  return 0;
}
