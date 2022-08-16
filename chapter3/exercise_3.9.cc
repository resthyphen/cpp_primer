#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  string s;
  char c;
  while(cin >> c){
    if(!ispunct(c))
      s += c;
  }
  cout << s << endl;
  return 0;
}
