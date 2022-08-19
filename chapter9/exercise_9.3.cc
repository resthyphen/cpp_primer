#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool func(vector<int>::iterator begin, vector<int>::iterator end, int n){
  while (begin != end) {
    //cout << *begin << endl;
    if(*begin == n)
      return true;
    ++begin;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  vector<int> v{1,2,3,4,5};
  auto begin = v.begin();
  auto end = v.end();
  cout << func(begin, end, 3) << endl;
  return 0;
}
