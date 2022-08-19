#include<iostream>
#include<vector>
#include<cstring>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main(int argc, char const *argv[]) {
  int a[] = {0, 1, 2, 3, 4, 5};
  vector<int> v(begin(a), end(a));
  
  cout << endl;
  return 0;
}
