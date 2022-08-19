#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> vec = {1,2,3,4,5};
  int ival = 2;
  cout << vec[ival++] << endl;
  cout << vec[ival] << endl;
  
  return 0;
}
