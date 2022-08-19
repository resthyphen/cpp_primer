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

struct children{
  string firstname;
  string lastname;
};

istream &read(istream &is, children &item){
  is >> item.firstname >> item.lastname;
  return is;
}


int main(int argc, char const *argv[]) {
  map<string, vector<string>> family;
  children item;
  while (read(cin, item)) {
    family[item.lastname].push_back(item.firstname);
  }

  for(const auto &i : family){
    cout << i.first <<": ";
    for(const auto &j : i.second)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}
