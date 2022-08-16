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


struct Base1 {
  void print(int i) const{
    cout << i << endl;
  }// public by default
protected:
  int ival;
  double dval;
  char cval = 'c';
private:
  int *id;
};

struct Base2 {
  void print(double d) const{
    cout << d << endl;
  }; // public by default
protected:
  double fval;
private:
  double dval;
};

struct Derived : public Base1 {
  void print(string s) const {
    cout << s << endl;
  }// public by default
protected:
  std::string sval = "ksdf";
  double dval;
};

struct MI : public Derived, public Base2 {
  void print(vector<double> dv){
    for(auto d : dv){
      cout << d << endl;
    }
  } // public by default

  void foo(double cval);
protected:
  int *ival;
  vector<double> dvec;
};

int ival;
double dval;

void MI::foo(double cval){
  int dval;
  dval = cval;
  dval = Base1::dval + Derived::dval;
  cout << ::ival << endl;
  cout << ::dval << endl;
  cout << Base1::ival << endl;
  cout << Base1::dval << endl;
  cout << Base1::cval << endl;
  cout << Base2::fval << endl;
  cout << Derived::sval << endl;
  cout << Derived::dval<< endl;
  cout << ival << endl;
  Base1::print(42);
  Base2::print(42);
  Derived::print("hello");
  //print(dvec);
  //Base2::fval = dvec[dvec.size() - 1];
  Derived::sval[0] = Base1::cval;
  cout << sval << endl;
}

int main(int argc, char const *argv[]) {
  MI mi;
  mi.foo(42);
  return 0;
}
