#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

int main() {
  int a, b;
  std::cin >> a >>b;
  auto f = [a](int i) { return a + i; };
  cout << f(b) << std::endl;
  return 0;
}
