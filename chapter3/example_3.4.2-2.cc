#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  double sought = 8;
  int end = v.size(), beg = 0;
  auto mid = beg + (end - beg)/2;
  while (mid != end && v[mid] != sought) {
    if (sought < v[mid]) // is the element we want in the first half?
      end = mid;
    else
      beg = mid + 1;
    mid = beg + (end - beg)/2;
  }
  cout << mid << endl;
  return 0;
}
