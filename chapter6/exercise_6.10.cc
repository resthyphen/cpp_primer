#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(int argc, char const *argv[]) {
  int a = 6, b = 12;
  swap(&a, &b);
  cout << "a = " << a << " " << "b = " << b << endl;

  return 0;
}
