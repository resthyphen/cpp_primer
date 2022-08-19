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

struct PersonInfo {
  string name;
  vector<string> phones;
};

bool valid(const smatch& m){
  // if there is an open parenthesis before the area code
  if(m[1].matched)
    // the area code must be followed by a close parenthesis
    // and followed immediately by the rest of the number or a space
    return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
  else
    // then there can't be a close after the area code
    // the delimiters between the other two components must match
    return !m[3].matched && m[4].str() == m[6].str();
}

string format(const string &nums){
  return  nums;
}

int main(int argc, char const *argv[]) {
  string line, word;
  vector<PersonInfo> people;
  string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
  regex r(phone); // a regex to find our pattern
  smatch m;
  string s ;
  while (getline(cin, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for(const auto &entry : people){
    ostringstream formatted, badNums;
    auto i = entry.phones.begin();
    s = "";
    while(i != entry.phones.end()){
      s += *i;
      s += " ";
      ++i;
    }
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it){
      // check whether the number's formatting is valid
      if (!valid(*it))       //dereference the iterator, we get an smatch object representing the current match
        badNums << entry.name << ":" << it->str(); // string in badNums
      else
        formatted << " " << format(it->str());
    }

    if (badNums.str().empty()) // there were no bad numbers
        cout << entry.name << " " // print the name
            << formatted.str() << endl;  // and reformatted numbers
    else
        cerr << "input error: " << entry.name
             << " invalid number(s) " << badNums.str() << endl;
  }
  return 0;
}
