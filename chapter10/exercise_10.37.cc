#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::list;

int main(int argc, char const *argv[]) {
  vector<int> v{1, 23, 4, 1, 6, 3, 4, 0, 8, 9};
  list<int> lst;
  auto iter = v.end() - 1 - 2;
  cout << *iter << endl;       // 1
  //copy(v.crbegin() + 2, v.crend() - 1 - 2, back_inserter(lst));
  copy(v.cbegin() + 3, v.cbegin() + 8,  back_inserter(lst));
  reverse(lst.begin(), lst.end());
  for(auto i : lst)
    cout << i << " " ;
  cout << endl;

  return 0;
}
