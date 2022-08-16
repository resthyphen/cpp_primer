#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int fact(int);

int fact(int val)
{
  int ret = 1; // local variable to hold the result as we calculate it
  while (val > 1)
    ret *= val--; // assign ret * val to ret and decrement val
  return ret; // return the result
}

int main(int argc, char const *argv[]) {
  int n;
  cout << "input a number to calculate factorial: " << endl;
  cin >> n;
  int j = fact(n);
  cout << n <<"! is " << j << endl;
  return 0;
}
