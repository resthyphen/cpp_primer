#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool is_captial(const string &s){
  for(string::size_type i = 0; i != s.size(); ++i){
    if(isupper(s[i]))
      return true;
  }
  return false;
}

void lowercase(string &s){
  for(string::size_type i = 0; i != s.size(); ++i){
    s[i] = tolower(s[i]);
  }
}

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  cout << is_captial(s) << endl;
  lowercase(s);
  cout << s << endl;
  return 0;
}
