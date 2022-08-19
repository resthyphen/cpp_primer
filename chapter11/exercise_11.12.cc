#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <utility>
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
  vector<pair<string, int>> v;
  while (cin) {
    string s;
    int i;
    cin >> s >> i;
    pair<string, int> p(s, i);
    v.push_back(p);
  }

  for(const auto &i : v)
    cout << i.first << " " << i.second << endl;

  return 0;
}
