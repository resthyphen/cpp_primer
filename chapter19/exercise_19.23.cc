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
#include "sales_data.h"
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
using std::function;
using std::mem_fn;

class Token{
public:
  // copy control needed because our class has a union with a string member
  Token(): tok(INT), ival{0} { }
  Token(const Token &t): tok(t.tok) { copyUnion(t); }
  Token &operator=(const Token&);
  Token(Token &&t): tok(t.tok) { copyUnion(t); }
  Token &operator=(Token &&t){
    if(this != &t){
      if (tok == STR && t.tok != STR) sval.~string();
      if (tok == STR && t.tok == STR)
        sval = t.sval; // no need to construct a new string
      else
        copyUnion(t); // will construct a string if t.tok is STR
      tok = t.tok;
    }
    return *this;
  }
  // if the union holds a string, we must destroy it; see § 19.1.2 (p. 824)
  ~Token() { if (tok == STR) sval.~string(); }
  // assignment operators to set the differing members of the union
  Token &operator=(const std::string&);
  Token &operator=(char);
  Token &operator=(int);
  Token &operator=(double);
private:
  enum {INT, CHAR, DBL, STR} tok; // discriminant
  union { // anonymous union
      char cval;
      int ival;
      double dval;
      string sval;
  };   // each Token object has an unnamed member of this unnamed union type
  // check the discriminant and copy the union member as appropriate
  void copyUnion(const Token&);
};

Token &Token::operator=(char c){
  if (tok == STR) sval.~string();
  cval = c;
  tok = CHAR;
  cout << typeid(tok).name() << endl;
  return *this;
}

Token &Token::operator=(int i){
  if (tok == STR) sval.~string();   // if we have a string, free it
  ival = i;   // assign to the appropriate member
  tok = INT;  // update the discriminant
  cout << typeid(tok).name() << endl;
  return *this;
}

Token &Token::operator=(double d){
  if (tok == STR) sval.~string();   // if we have a string, free it
  dval = d;   // assign to the appropriate member
  tok = DBL;  // update the discriminant
  cout << typeid(tok).name() << endl;
  return *this;
}

Token &Token::operator=(const std::string &s){
  if (tok == STR) // if we already hold a string, just do an assignment
    sval = s;
  else
    new(&sval) string(s); // otherwise construct a string
  tok = STR; // update the discriminant
  cout << typeid(tok).name() << endl;
  return *this;
}


void Token::copyUnion(const Token &t){
  switch (t.tok) {
    case Token::INT: ival = t.ival; break;
    case Token::CHAR: cval = t.cval; break;
    case Token::DBL: dval = t.dval; break;
    case Token::STR: new(&sval) string(t.sval); break;
  }
}

Token &Token::operator=(const Token &t){
  // if this object holds a string and t doesn't, we have to free the old string
  if (tok == STR && t.tok != STR) sval.~string();
  if (tok == STR && t.tok == STR)
    sval = t.sval; // no need to construct a new string
  else
    copyUnion(t); // will construct a string if t.tok is STR
  tok = t.tok;
  return *this;
}

int main(int argc, char const *argv[]) {
  Token t;
  t = 'c';
  return 0;
}
