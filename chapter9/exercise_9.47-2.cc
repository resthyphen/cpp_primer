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
  string s("ab2c3d7R4E6");
  string::size_type pos;
  char c = 'a';
  //pos = s.find_first_not_of(c, 1);
  //cout << pos << endl;

  for(; c <= 'z'; c++){
    for(string::size_type i = 0; i != s.size(); ++i){
      if(s.find_first_not_of(c, i) > i){
        cout << c << ":" << i << endl;
        break;
      }
    }
    for(string::size_type i = 0; i != s.size(); ++i){
      if(s.find_first_not_of(toupper(c), i) > i){
        cout << s[i] << ":" << i << endl;
        break;
      }
    }
  }

  c = '0';
  for(; c <= '9'; c++){
    for(string::size_type i = 0; i != s.size(); ++i){
      if(s.find_first_not_of(c, i) > i){
        cout << c << ":" << i << endl;
        break;
      }
    }
  }

  return 0;
}
