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
  using line_no = std::vector<std::string>::size_type;
  map<string, shared_ptr<set<line_no>>> wm;
  string word;
  int n;
  while(cin >> word){
      if(!wm[word])
        wm[word].reset(new set<line_no>);
      for(line_no i = 1; i != 11; ++i)
        (*wm[word]).insert(i);
  }
  for(const auto &i : wm){
    cout << i.first << " : ";
      for(const auto &j : *(i.second))
        cout << j << " ";
      cout << endl;
  }
  return 0;
}
