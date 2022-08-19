#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  string s = "word";
  string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
  cout << pl << endl;
  return 0;
}
