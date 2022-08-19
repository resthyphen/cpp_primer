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
  vector<int> v = {0, 1, 2, 3, 4, 5};
  int a[6];
  for(int i = 0; i < 6; ++i)
    a[i] = v[i];
  for(auto i : a)
    cout<< i << " ";
  cout << endl;
  return 0;
}
