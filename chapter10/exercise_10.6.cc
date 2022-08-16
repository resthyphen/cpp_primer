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

int main(int argc, char const *argv[]) {
  vector<int> v{1,1,2,2,3,4,5};
  fill_n(v.begin(), v.size(), 0);
  auto iter = v.cbegin();
  while(iter != v.cend()){
    cout << *iter << " " ;
    ++iter;
  }
  cout << endl;
  return 0;
}
