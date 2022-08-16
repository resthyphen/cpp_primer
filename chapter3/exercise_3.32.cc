#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int arr[10];
  for(int i = 0; i < 10; ++i )
    arr[i] = i;
  int arr2[10];
  for(int i = 0; i < 10; ++i )
    arr2[i] = arr[i];
  vector<int> v;
  for(int i = 0; i < 10; ++i)
    v.push_back(i);
  vector<int> v2 = v;
  return 0;
}
