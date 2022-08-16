#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  string s("Hello World!!!");
  char a = 'X';
  for(char c : s)
    c = a;
  cout << s << endl;
  return 0;
}
