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
using std::multimap;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;

class PrintString {
public:
  PrintString(ostream &o = cout, char c = ' '): os(o), sep(c) { }
  void operator()(const string &s) const {
    os << s << sep;
  }

private:
  ostream &os; // stream on which to write
  char sep; // character to print after each output
};

int main(int argc, char const *argv[]) {
  PrintString printer;
  vector<string> v;
  string s;
  while(cin >> s){
    v.push_back(s);
  }
  //for(const auto &i : v)
    //printer(i);
  for_each(v.begin(), v.end(), PrintString(cerr, '\n'));
  return 0;
}
