#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int abs(int n){
  if(n < 0)
    n = n * -1;
  return n;
}

int main(int argc, char const *argv[]) {
  int n = -5;
  cout << n << " absolute value is " << abs(n) << endl;
  return 0;
}
