#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main(int argc, char const *argv[]) {
  int ia1[] = {0,2,4,6,8};
  int ia2[] = {0,1,3,5,7};
  cout << (ia1 == ia2) << endl;
  vector<int> v1 = {0,2,4,6,8};
  vector<int> v2 = {0,1,3,5,7};
  cout << (v1 == v2) << endl;
  return 0;
}
