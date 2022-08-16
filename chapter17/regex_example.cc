#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <regex>
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
using std::exception;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::less;
using namespace std::placeholders;
//using namespace std;
using std::allocator;
using std::plus;
using std::begin;
using std::end;
using std::ostringstream;
using std::hash;
using std::unordered_multiset;
using std::tuple;
using std::make_tuple;
using std::get;
using std::make_pair;
using std::bitset;
using std::regex;
using std::smatch;

int main(int argc, char const *argv[]) {
    // find the characters ei that follow a character other than c
  string pattern("[^c]ei");
  // we want the whole word in which our pattern appears
  pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
  regex r(pattern); // construct a regex to find pattern
  smatch results; // define an object to hold the results of a search
  // define a string that has text that does and doesn't match pattern
  string test_str = "receipt freind theif receive";
  // use r to find a match to pattern in test_str
  if (regex_search(test_str, results, r)) // if there is a match
    cout << results.str() << endl; // print the matching word
  return 0;
}
