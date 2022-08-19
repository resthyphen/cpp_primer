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
    return s.size() >= low && s.size() <= high - 1 || s.size() >= high;
  }

private:
  size_t low;
  size_t high;
};

int main(int argc, char const *argv[]) {
  string f = "file";
  ifstream in(f);
  vector<string> v;
  istream_iterator<string> in_iter(in), end;
  cout << count_if(in_iter, end, Test(1, 10)) << endl;
//cout << count_if(in_iter, end, Test(10, 20)) << endl;
  return 0;
}
