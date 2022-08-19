#ifndef CHAPTER10_H
#define CHAPTER10_H

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
#include <random>
#include <iomanip>
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
using namespace std::regex_constants;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
using std::bernoulli_distribution;
using std::noskipws;
using std::uppercase;
using std::showbase;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::right;
using std::setw;
using std::fstream;

namespace chapter10{
  class QueryResult;
  class TextQuery {
    friend class QueryResult;
  public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
  private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    map<string, shared_ptr<set<line_no>>> wm;
  };

  class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);

  public:
    using line_no = vector<string>::size_type;
    QueryResult(std::string s,
      std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f):
    sought(s), lines(p), file(f) { }

    set<line_no>::iterator begin(){
      return (*lines).begin();
    }

    set<line_no>::iterator end(){
      return (*lines).end();
    }

    shared_ptr<vector<string>> get_file(){
      return file;
    }

  private:
    std::string sought; // word this query represents
    std::shared_ptr<std::set<line_no>> lines; // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
  };

  TextQuery::TextQuery(ifstream &is): file(new vector<string>){
    string text;
    while (getline(is, text)) { // for each line in the file
      file->push_back(text); // remember this line of text
      int n = file->size() - 1; // the current line number
      istringstream line(text); // separate the line into words
      string word;
      while (line >> word) { // for each word in that line
        // if word isn't already in wm, subscripting adds a new entry
        if(ispunct(word[0]))
          word.erase(word.begin());
        if(ispunct(word[word.size() - 1]))
          word.pop_back();
        auto &lines = wm[word]; // lines is a shared_ptr
        if (!lines) // that pointer is null the first time we see word
          lines.reset(new set<line_no>); // allocate a new set
        lines->insert(n); // insert this line number
      }
    }
  }

  QueryResult TextQuery::query(const string &sought) const{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
      return QueryResult(sought, nodata, file); // not found
    else
      return QueryResult(sought, loc->second, file);
  }

  string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr > 1) ? word + ending : word;
  }

  ostream &print(ostream & os, const QueryResult &qr){
  // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
  // print each line in which the word appeared
    for (auto num : *qr.lines) // for every element in the set
      // don't confound the user with text lines starting at 0
      os << "\t(line " << num + 1 << ") "
         << *(qr.file->begin() + num) << endl;
    return os;
  }

  void runQueries(ifstream &infile){
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while (true) {
      cout << "enter word to look for, or q to quit: ";
      string s;
      // stop if we hit end-of-file on the input or if a 'q' is entered
      if (!(cin >> s) || s == "q") break;
      // run the query and print the results
      print(cout, tq.query(s)) << endl;
    }
  }
}

#endif
