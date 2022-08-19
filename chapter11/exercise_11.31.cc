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
using std::multimap;

int main(int argc, char const *argv[]) {
  map<string, string> authors;
  string author;
  string bookname;
  while(getline(cin, author) && getline(cin, bookname)){
    authors.insert({author, bookname});
  }
  authors.insert({"Barth, John", "Sot-Weed Factor"});
  authors.insert({"Barth, John", "Lost in the Funhouse"});
  string search_item("Alain de Botton");
  //auto iter = authors.find(search_item);

  //for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
  //  cout << pos.first->second << endl;

  if(authors.find(search_item) == authors.end())
    cout << search_item << " not found" << endl;
  else
    authors.erase(search_item);

  for(const auto &i : authors)
    cout << i.first << ": " << i.second << endl;

  return 0;
}
