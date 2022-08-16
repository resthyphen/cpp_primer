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

class FunctionObj {
public:
  FunctionObj() = default;

  int operator() (int a, int b, int c) const{
    if(a > 0)
      return b;
    else
      return c;
  }
};

int main(int argc, char const *argv[]) {
  FunctionObj fo;
  int i = fo(-1, -2, 3);
  cout << i << endl;
  return 0;
}
