#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
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
using std::multiset;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using namespace std::placeholders;
//using namespace std;

int main(int argc, char const *argv[]) {
  string word;
  cin >> word;
  auto i = word.begin();
  while (i != word.end()) {
    if(ispunct(*i))
      i = word.erase(i);
    else
      ++i;
  }

  cout << word << endl;
  return 0;
}
