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
  Test(int n = 0):a(n){}

  bool operator()(int b) const{
    return a==b;
  }

private:
  int a;
};

int main(int argc, char const *argv[]) {
  vector<int> v;
  int n;
  Test test(2);
  while(cin >> n)
    v.push_back(n);
  replace_if(v.begin(), v.end(), test, -2);
  for(const auto &i : v)
    cout << i << endl;
  return 0;
}
