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
using std::istringstream;

int main(int argc, char const *argv[]) {
  map<string, list<int>> word_occurs;
  string line, word;
  int lineno;
  while (getline(cin, line)) {
    ++lineno;
    istringstream record(line);
    while(record >> word){
      word_occurs[word].push_back(lineno);
    }
  }
  //cout << lineno << endl;
  for(const auto &i : word_occurs){
    cout << i.first << " occurs in: ";
    for(const auto &j : i.second)
      cout << j << " ";
    cout << " line.";
    cout << endl;
  }
  return 0;
}
