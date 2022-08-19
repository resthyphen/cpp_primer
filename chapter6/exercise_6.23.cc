#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


void print_i(const int i){
  cout << i << endl;
}

void print_j(const int *beg, const int *end){
  while(beg != end)
    cout << *beg++ << endl;
}

void print(const (&arr)[2]){
  for(auto &i : arr)
    cout << e << endl;
}
