#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
#include <functional>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using namespace std::placeholders;

int main(int argc, char const *argv[]) {
  list<int> lst = {1,2,3,4};
  list<int> lst2, lst3;
  copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
  copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
  auto iter2 = lst2.cbegin();
  auto iter3 = lst3.cbegin();
  while(iter2 != lst2.cend()){
    cout << *iter2 << " ";
    ++iter2;
  }
  cout << endl;
  while(iter3 != lst3.cend()){
    cout << *iter3 << " ";
    ++iter3;
  }
  cout << endl;
  return 0;
}
