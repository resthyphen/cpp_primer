#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;

void vec_print(const vector<int>::iterator bg, const vector<int>::iterator ed) {
  if(bg == ed)
    return;
  std::cout << *bg << " ";
  vec_print(bg + 1, ed);
}

int main(int argc, char const *argv[]) {
  vector<int> v;
  int i;
  while (cin >> i) {
    v.push_back(i);
  }
  vec_print(v.begin(), v.end());
  return 0;
}
