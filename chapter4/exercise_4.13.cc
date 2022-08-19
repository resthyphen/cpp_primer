#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int i;
  double d;
  d = i = 3.5;
  cout << d << " " << i << endl;
  i = d = 3.5;
  cout << d << " " << i << endl;
  return 0;
}
