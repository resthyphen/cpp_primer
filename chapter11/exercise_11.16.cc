#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
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

int main(int argc, char const *argv[]) {
  map<string, int> m{{"first", 0}, {"second", 0}, {"third", 0}};
  auto iter = m.begin();
  int n;
  while (iter != m.end()) {
    cin >> n;
    iter->second = n;
    ++iter;
  }
  for(const auto &i : m){
    cout << i.first << ":" << i.second << endl;
  }
  return 0;
}
