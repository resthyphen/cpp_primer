#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int i = 1, j = 2;
  double slope = static_cast<double>(i) / j;
  char c = 'a';
  const char *pc = &c;
  string s = static_cast<string>(pc);
  //cout << q << endl;
  //cout << *q << endl;
  cout << s << endl;
  return 0;
}
