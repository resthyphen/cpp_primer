#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int sum;
  int val;
  while(val <= 10)
    sum += val, ++val;
  cout << sum << endl;
  return 0;
}
