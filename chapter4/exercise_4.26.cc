#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  //unsigned long quiz1 = 0;
  unsigned quiz1 = 0;
  quiz1 = quiz1 | 1UL << 27;
  cout << quiz1 << endl;
  return 0;
}
