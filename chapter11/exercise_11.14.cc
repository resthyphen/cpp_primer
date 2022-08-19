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

struct children{
  string firstname;
  string lastname;
  string birthday;
};

istream &read(istream &is, children &item){
  is >> item.firstname >> item.lastname >> item.birthday;
  return is;
}

int main(int argc, char const *argv[]) {
  map<string, vector<pair<string, string>> > family;
  children item;
  while (read(cin, item)) {
    family[item.lastname].push_back({item.firstname + " " + item.lastname, item.birthday});
  }

  for(const auto &i : family){
    cout << i.first <<": ";
    for(const auto &j : i.second)
      cout << j.first << " " << j.second << " ";
    cout << endl;
  }
  return 0;
}
