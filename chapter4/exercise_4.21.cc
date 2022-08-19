#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> v {1,2,3,4,5,6,7,8,9};
  auto iter = v.begin();
  while (iter != v.end()) {
    *iter = (*iter % 2 != 0)?  *iter *2 : *iter ;
    ++iter;
  }
  iter = v.begin();
  while (iter != v.end()) {
    cout << *iter++ << endl;
  }
  return 0;
}
