#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char const *argv[]) {
  int i = 6, j = 12;
  swap(i, j);
  cout << "i = " << i << " " << "j = " << j << endl;

  return 0;
}
