#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void swap(int *pa, int *pb){
  int *tmp = pa;
  pa = pb;
  pb = tmp;
}
