#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
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
using std::map;
using std::set;
using std::pair;
using std::multimap;
using std::multiset;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;

int main(int argc, char const *argv[]) {
  vector<int> v = {1,2,3,4};
  vector<int> v2, v3;
  auto it = inserter(v, v.begin() + 2);
  *it = 10;
  for(auto i : v)
    cout << i << " " ;
  cout << endl;
  auto it2 = inserter(v3, v3.begin());
  copy(v.cbegin(), v.cend(), it2);
  //cout << *it2 << endl;
  for(auto i : v3)
    cout << i << " " ;
  cout << endl;
  return 0;
}
