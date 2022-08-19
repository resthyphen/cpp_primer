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
  vector<int> vec; list<int> lst; int i;
  while (cin >> i)
    lst.push_back(i);

  vec.resize(lst.size());
  copy(lst.begin(), lst.end(), vec.begin());
  auto iter = vec.cbegin();
  while(iter != vec.cend()){
    cout << *iter << " " ;
    ++iter;
  }
  cout << endl;
  return 0;
}
