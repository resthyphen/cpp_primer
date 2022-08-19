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

int main(int argc, char const *argv[]) {
  map<string, size_t> word_count;
  string word;
  while (cin >> word)
    ++word_count[word];
  for(const auto &w : word_count)
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  return 0;
}
