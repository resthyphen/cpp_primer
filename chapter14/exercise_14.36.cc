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

class GetStr {
public:
  GetStr(istream &i = cin): is(i){ }
  string operator()() const {
    string s;
    getline(is, s);
    return is? s : string();
  }

private:
  istream &is;
};


int main(int argc, char const *argv[]) {
  vector<string> v;
  string line;
  GetStr getStr;
  // while(cin){
  //   line = getStr();
  //   v.push_back(line);
  // }

  for(string tmp; !(tmp = getStr()).empty(); v.push_back(tmp));
  for(const auto &i : v)
    cout << i << endl;
  return 0;
}
