#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  string s("Hello World!!!");
  for(auto &c : s)
    c = toupper(c);
  cout << s << endl;
  return 0;
}
