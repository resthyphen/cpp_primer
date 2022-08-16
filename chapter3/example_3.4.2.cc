#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  double sought = 2;
  auto beg = v.begin(), end = v.end();
  auto mid = v.begin() + (end - beg)/2;
  while (mid != end && *mid != sought) {
    if (sought < *mid) // is the element we want in the first half?
      end = mid;
    else
      beg = mid + 1;
    mid = beg + (end - beg)/2;
  }
  if(sought == *mid)
    cout << "find" << endl;
  else
    cout << *mid << endl;
  return 0;
}
