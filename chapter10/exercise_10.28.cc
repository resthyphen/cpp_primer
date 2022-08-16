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
  vector<int> v{1,2,3,4,5,6,7,8,9};
  list<int> lst2, lst3, lst4;
  copy(v.cbegin(), v.cend(), inserter(lst2, lst2.begin()));
  for(auto &i : lst2)
    cout << i << " ";
  cout << endl;
  copy(v.cbegin(), v.cend(), back_inserter(lst3));
  for(auto &i : lst3)
    cout << i << " ";
  cout << endl;
  copy(v.cbegin(), v.cend(), front_inserter(lst4));
  for(auto &i : lst4)
    cout << i << " ";
  cout << endl;
  return 0;
}
