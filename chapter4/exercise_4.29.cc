#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int x[10];
  int *p = x;
  size_t sz = sizeof x;
  cout << sz << endl;
  cout << sizeof(x)/sizeof(*x) << endl;
  cout << sizeof(p)/sizeof(*p) << endl;
  return 0;
}
