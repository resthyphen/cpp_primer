#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void reset(int *ip) {
    *ip = 0; // changes the value of the object to which ip points
    ip = 0; // changes only the local copy of ip; the argument is unchanged
}

int main(int argc, char const *argv[]) {
  int a = 10;
  int b;
  const int c = a;
  b = c;
  cout << b << endl;
}

string (&func(int i)) [10];
