#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  string s("Hello World!!!");
  int i = 0;
  while(i < s.size()){
    s[i] = 'X';
    ++i;
  }
  cout << s << endl;
  return 0;
}
