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

auto f = [](int a, int b){ return a + b; };

int main(int argc, char const *argv[]) {
  cout << f(3, 2) << endl;
  return 0;
}
