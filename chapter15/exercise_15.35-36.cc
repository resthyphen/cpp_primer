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
    std::shared_ptr<std::vector<std::string>> f):
  sought(s), lines(p), file(f) { }
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
  Query(const std::string&); // builds a new WordQuery
  // interface functions: call the corresponding Query_base operations
  QueryResult eval(const TextQuery &t) const{
    return q->eval(t);
  }
  string rep() const {
    cout << "Query::rep()" << endl;
    return q->rep();
  }

private:
  Query(std::shared_ptr<Query_base> query): q(query) {
    cout << "Query(std::shared_ptr<Query_base> query)" << endl;
   }
  shared_ptr<Query_base> q;
};

ostream& operator<<(std::ostream &os, const Query &query)
{
// Query::rep makes a virtual call through its Query_base pointer to rep()
  return os << query.rep();
}

class WordQuery: public Query_base {
  friend class Query; // Query uses the WordQuery constructor
  WordQuery(const std::string &s): query_word(s) { }
  // concrete class: WordQuery defines all inherited pure virtual functions
  QueryResult eval(const TextQuery &t) const{
    return t.query(query_word);
  }
  std::string rep() const {
    cout << "WordQuery::rep()" << endl;
    return query_word;
  }
  std::string query_word; // word for which to search
};

inline
Query::Query(const std::string &s): q(new WordQuery(s)) {
  cout << "Query(const std::string &s)" << endl;
}

class NotQuery: public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q): query(q) {
    cout << "NotQuery(const Query &q)" << endl;
  }
  // concrete class: NotQuery defines all inherited pure virtual functions
  std::string rep() const {
    cout << "NotQuery::rep()" << endl;
    return "~(" + query.rep() +")";
  }
  QueryResult eval(const TextQuery &t) const;
  Query query;
};

inline Query operator~(const Query &operand){
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base {
protected:
  BinaryQuery(const Query &l, const Query &r, std::string s):
    lhs(l), rhs(r), opSym(s){
      cout << "BinaryQuery(const Query &l, const Query &r, std::string s)" << endl;
    }

  string rep() const {
    cout << "BinaryQuery::rep()" << endl;
    return  "(" + lhs.rep() + " " +  opSym + " " + rhs.rep() + ")";
  }

  Query lhs, rhs;
  string opSym;
};

class AndQuery: public BinaryQuery{
  friend Query operator& (const Query&, const Query&);
  AndQuery(const Query &left, const Query &right):
                BinaryQuery(left, right, "&") {
        cout << "AndQuery(const Query &left, const Query &right)" << endl;
  }
  // concrete class: AndQuery inherits rep and defines the remaining pure virtual
  QueryResult eval(const TextQuery &t) const {};
};

inline Query operator&(const Query &lhs, const Query &rhs){
  return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery{
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query &left, const Query &right):
                BinaryQuery(left, right, "|") {
        cout << "OrQuery(const Query &left, const Query &right)" << endl;
  }
  QueryResult eval(const TextQuery &t) const {};
};

inline Query operator|(const Query &lhs, const Query &rhs){
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main(int argc, char const *argv[]) {
  Query q = Query("fiery") & Query("bird") | Query("wind");
  cout << q << endl;
  return 0;
}
