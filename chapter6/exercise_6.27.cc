#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;

int intSum(initializer_list<int> il){
  int sum = 0;
  for(auto beg = il.begin(); beg != il.end(); ++beg)
    sum += *beg;
  return sum;
}

int main(int argc, char const *argv[]) {
  cout << intSum({1,2,3,4,5}) << endl;
  return 0;
}
