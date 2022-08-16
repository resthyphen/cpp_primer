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
#include <functional>
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
using std::plus;
using std::negate;
using std::less;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using namespace std::placeholders;

int main(int argc, char const *argv[]) {
  greater<int> g;
  vector<int> vi;
  cout << g(11251,1024) << endl;
  count_if(vi.begin(), vi.end(), bind(greater<int>(), _1, 1024));

  not_equal_to<string> n;
  cout << n("sdf", "pooh") << endl;
  vector<string> vs;
  find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), _1, "pooh"));

  transform(vi.begin(), vi.end(), vi.begin(), bind(multiplies<int>(), _1, 2));
  return 0;
}
