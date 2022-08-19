#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;

int factorial(int val){
  if (val > 1)
    return factorial(val-1) * val;
  return 1;
}

int main(int argc, char const *argv[]) {
  cout << factorial(-5) << endl;
  return 0;
}
