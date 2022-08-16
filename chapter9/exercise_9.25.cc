#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

int main(int argc, char const *argv[]) {
  vector<int> iv{1,2,3,4,5,6};
  auto iter1 = iv.end(), iter2 = iv.end();
  iv.erase(iter1, iter2);
  for(auto i : iv)
    cout << i << endl;
  return 0;
}
