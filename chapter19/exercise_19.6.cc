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
#include <cstdlib>
#include <typeinfo>
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
using std::bad_alloc;
using std::bad_cast;

class Query_base;
class Query;
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
    std::shared_ptr<std::set<line_no>> p,
    std::shared_ptr<std::vector<std::string>> f):sought(s), lines(p), file(f) { }

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
  os << "Executing Query for: " << qr.sought << endl;
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << make_plural(qr.lines->size(), "time", "s") << endl;
// print each line in which the word appeared
  for (auto num : *qr.lines) // for every element in the set
    // don't confound the user with text lines starting at 0
    os << "\t(line " << num + 1 << ") "
       << *(qr.file->begin() + num) << endl;
  return os;
}

class Query_base{
  friend class Query;

protected:
  using line_no = TextQuery::line_no; // used in the eval functions
  virtual ~Query_base() = default;

private:
  // eval returns the QueryResult that matches this Query
  virtual QueryResult eval(const TextQuery&) const = 0;
  // rep is a string representation of the query
  virtual std::string rep() const = 0;

};

// interface class to manage the Query_base inheritance hierarchy
class Query {
  // these operators need access to the shared_ptr constructor
  friend Query operator~(const Query &);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
public:
  Query() = default;
  Query(const std::string&); // builds a new WordQuery
  // interface functions: call the corresponding Query_base operations
  QueryResult eval(const TextQuery &t) const{
    return q->eval(t);
  }
  string rep() const {
    return q->rep();
  }

private:
  Query(std::shared_ptr<Query_base> query): q(query) { }
  shared_ptr<Query_base> q;
};

ostream& operator<<(std::ostream &os, const Query &query)
{
// Query::rep makes a virtual call through its Query_base pointer to rep()
  return os << query.rep();
}

class WordQuery: public Query_base {
  friend class Query; // Query uses the WordQuery constructor
public:
  WordQuery() = default;
  WordQuery(const std::string &s): query_word(s) { }
  // concrete class: WordQuery defines all inherited pure virtual functions
  QueryResult eval(const TextQuery &t) const{
    return t.query(query_word);
  }
  std::string rep() const {
    return query_word;
  }
  std::string query_word; // word for which to search
};

inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }

class NotQuery: public Query_base {
  friend Query operator~(const Query &);
public:
  NotQuery() = default;
  NotQuery(const Query &q): query(q) { }
  // concrete class: NotQuery defines all inherited pure virtual functions
  std::string rep() const {
    return "~(" + query.rep() +")";
  }
  QueryResult eval(const TextQuery&) const;
  Query query;
};

// returns the lines not in its operand's result set
QueryResult NotQuery::eval(const TextQuery& text) const{
  // virtual call to eval through the Query operand
  auto result = query.eval(text);
  // start out with an empty result set
  auto ret_lines = make_shared<set<line_no>>();
  // we have to iterate through the lines on which our operand
  auto beg = result.begin(), end = result.end();
  // for each line in the input file, if that line is not in result,
  // add that line number to ret_lines
  auto sz = result.get_file()->size();
  for (size_t n = 0; n != sz; ++n) {
    // if we haven't processed all the lines in result
    // check whether this line is present
    if (beg == end || *beg != n)
      ret_lines->insert(n);   // if not in result, add this line
    else if (beg != end)
      ++beg; // otherwise get the next line number in result if there is one
  }
  return QueryResult(rep(), ret_lines, result.get_file());
}



inline Query operator~(const Query &operand){
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base {
protected:
  BinaryQuery() = default;
  BinaryQuery(const Query &l, const Query &r, std::string s):
    lhs(l), rhs(r), opSym(s){}

  string rep() const {
    return  "(" + lhs.rep() + " " +  opSym + " " + rhs.rep() + ")";
  }

  Query lhs, rhs;
  string opSym;
};

class AndQuery: public BinaryQuery{
  friend Query operator& (const Query&, const Query&);
public:
  AndQuery() = default;
  AndQuery(const Query &left, const Query &right):
                BinaryQuery(left, right, "&") { }
  // concrete class: AndQuery inherits rep and defines the remaining pure virtual
  QueryResult eval(const TextQuery&) const;
};

// returns the intersection of its operands' result sets
QueryResult AndQuery::eval(const TextQuery& text) const{
  // virtual calls through the Query operands to get result sets for the operands
  auto left = lhs.eval(text), right = rhs.eval(text);
  // set to hold the intersection of left and right
  auto ret_lines = make_shared<set<line_no>>();
  // writes the intersection of two ranges to a destination iterator
  // destination iterator in this call adds elements to ret
  set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                    inserter(*ret_lines, ret_lines->begin()));

  return QueryResult(rep(), ret_lines, left.get_file());
}



inline Query operator&(const Query &lhs, const Query &rhs){
  return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));  //implicitly convert to Query
}

class OrQuery: public BinaryQuery{
  friend Query operator|(const Query&, const Query&);
public:
  OrQuery() = default;
  OrQuery(const Query &left, const Query &right):
                BinaryQuery(left, right, "|") { }
  QueryResult eval(const TextQuery&) const;
};

// returns the union of its operands' result sets
QueryResult OrQuery::eval(const TextQuery& text) const{
  // virtual calls through the Query members, lhs and rhs
  // the calls to eval return the QueryResult for each operand
  auto right = rhs.eval(text), left = lhs.eval(text);
  // copy the line numbers from the left-hand operand into the result set
  auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
  // insert lines from the right-hand operand
  ret_lines->insert(right.begin(), right.end());
  // return the new QueryResult representing the union of lhs and rhs
  return QueryResult(rep(), ret_lines, left.get_file());

}


inline Query operator|(const Query &lhs, const Query &rhs){
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

void runQueries(ifstream &infile, Query q){
  // infile is an ifstream that is the file we want to query
  TextQuery tq(infile); // store the file and build the query map
  // iterate with the user: prompt for a word to find and print results
  // while (true) {
  //   cout << "enter word to look for, or q to quit: ";
  //   string s;
  //   // stop if we hit end-of-file on the input or if a 'q' is entered
  //   if (!(cin >> s) || s == "q") break;
  //   // run the query and print the results
  //   print(cout, tq.query(s)) << endl;
  // }
  print(cout, q.eval(tq)) << endl;
}

int main(int argc, char const *argv[]) {
  Query_base *qb =  new OrQuery;
  AndQuery *aq = dynamic_cast< AndQuery* >(qb);
  if(aq)
    cout << "succeed" << endl;
  else
    cout << "fail" << endl;
  return 0;
}
