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
using std::regex_error;
using std::sregex_iterator;
using std::regex_iterator;
using std::cregex_iterator;

int main(int argc, char const *argv[]) {
  ifstream in("file2");
  string file;
  string temp;
  while(getline(in,temp)){
    file += temp + " ";
  }
  //cout << file << endl;
  // find the characters ei that follow a character other than c
  string pattern("[^c]ei");
  // we want the whole word in which our pattern appears
  pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
  regex r(pattern, regex::icase); // we'll ignore case in doing the match
  // it will repeatedly call regex_search to find all matches in file
  for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it){
     //cout << it->str() << endl;
     //cout << it->prefix().str() << endl;
     auto pos = it->prefix().length();
     cout << pos << endl;
     pos = pos > 40 ? pos - 40 : 0;
      cout << it->prefix().str().substr(pos)
           << "\n\t\t>>> " << it->str() << " <<<\n" 
           << it->suffix().str()<< endl;
   }
  return 0;
}
