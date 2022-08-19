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

class Test{

public:
  Test(size_t l, size_t h):low(l), high(h){}
  bool operator()(const string &s) const{
    return s.size() >= low && s.size() <= high;
  }

private:
  size_t low;
  size_t high;
};

int main(int argc, char const *argv[]) {
  string f = "file";
  ifstream in(f);
  vector<string> v;
  istream_iterator<string> in_iter(in), eof;

  // string word;
  // while(in >> word)
  //   v.push_back(word);
  //
  // cout << v.size() << endl;

  // Test test(1, 10);

  // for(const auto &i : v)
  //   cout << i << endl;

  cout << count_if(in_iter, eof, Test(1, 10)) << endl;
  return 0;
}
