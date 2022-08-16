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

struct Base {
  void bar(int i){
    ival = i;
  } // public by default
  Base() = default;

  Base(int i):ival(i){
    cout << "Base(int i)" << endl;
  }
  Base(const Base &orig):ival(orig.ival){
    cout << "Base(const Base &orig)" << endl;
  }

protected:
  int ival;
};

struct D1: virtual public Base{
  void bar(char c){
    cval = c;
  }
  D1() = default;
  D1(int i, char c): Base(i), cval(c){
    cout << "D1(int i, char c)" << endl;
  }
  D1(const D1 &orig): Base(orig), cval(orig.cval){
    cout << "D1(const D1 &orig)" << endl;
  }
protected:
  char cval;
};

struct D2: virtual public Base{
  void foo(int i){
    ival = i;
  }
  D2() = default;
  D2(int i, char c):Base(i), ival(i + 1), cval(c){
    cout << "D2(int i1, int i2, char c)" << endl;
  }
  D2(const D2 &orig):Base(orig), ival(orig.ival), cval(orig.cval){
    cout << "D2(const D2 &orig)" << endl;
  }
protected:
  int ival;
  char cval;
};

class VMI : public D1, public D2 {
public:
  VMI() = default;
  VMI(int i, char c, string s): D1(i, c), D2(i, c), str(s), Base(i){
    cout << "VMI(int i, char c, string s)" << endl;
  }
  VMI(const VMI &orig): Base(orig), D1(orig), D2(orig), str(orig.str){
    cout << "VMI(const VMI &orig)" << endl;
  }
  void print(){
    cout << ival << endl;   //D2::ival
  }
private:
  string str;
};

int main(int argc, char const *argv[]) {
  VMI vmi1(1,  'a', "multiple");
  vmi1.print();
  cout << endl;
  VMI vmi2 = vmi1;
  return 0;
}
