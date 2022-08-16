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

class ShorterString {
public:
  bool operator()(const string &s1, const string &s2) const
    { return s1.size() < s2.size(); }
};

class SizeComp {
public:
  SizeComp(size_t n): sz(n) { } // parameter for each captured variable
  // call operator with the same return type, parameters, and body as the lambda
  bool operator()(const string &s) const {
    return s.size() >= sz;
  }

private:
  size_t sz; // a data member for each variable captured by value
};

class PrintString {
public:
  PrintString(ostream &o = cout, char c = ' '): os(o), sep(c) { }
  void operator()(const string &s) const {
    os << s << sep;
  }

private:
  ostream &os; // stream on which to write
  char sep; // character to print after each output
};

void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending){
  return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
  elimDups(words); // put words in alphabetical order and remove duplicates
  // sort words by size, but maintain alphabetical order for words of the same size
  stable_sort(words.begin(), words.end(), ShorterString());
  // get an iterator to the first element whose size() is >= sz
  auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
  // compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
      // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), PrintString());
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  biggies(words, 5);
  return 0;
}
