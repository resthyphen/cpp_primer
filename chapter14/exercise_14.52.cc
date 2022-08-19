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
#include <functional>
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
using std::plus;
using std::negate;
using std::less;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using std::divides;
using std::modulus;
using namespace std::placeholders;
using std::function;

class LongDouble;

class SmallInt {
friend SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs);
friend class LongDouble;

public:
  SmallInt(int i = 0): val(i){ if (i < 0 || i > 255)
    throw std::out_of_range("Bad SmallInt value");
  }

  operator int() const { return val; }

private:
  std::size_t val;
};

SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs){
  SmallInt sum(lhs);
  sum.val += rhs.val;
  return sum;
}

struct LongDouble {
  friend LongDouble operator+(LongDouble &lhs, double d);

  LongDouble(double d = 0.0):val(d) {}

  operator double() const {
    cout << "operator double()" << endl;
    return val;
  }

  LongDouble operator+(const SmallInt &si){
    cout << "LongDouble operator+" << endl;
    LongDouble sum(*this);
    sum.val += si.val;
    return sum;
  }

  operator float() const {
    cout << "operator float()" << endl;
    return val;
  }

  long double val;
};

LongDouble operator+(LongDouble &lhs, double d){
  LongDouble sum(lhs);
  sum.val += d;
  return sum;
}

void calc(int i) {
  std::cout << "void calc(int)" << std::endl;
}

void calc(LongDouble ld) {
  std::cout << "void calc(LongDouble)" << std::endl;
}

int main() {
  LongDouble ldObj;
  //int ex1 = ldObj;  // Error
  // Both convert to `double` and `float` are equally good match
  float ex2 = ldObj;  // OK
  // match `operator float`
  cout << ex2 << endl;
  double dval;
  calc(dval);
  SmallInt si = 4;
  LongDouble ld = 1;
  //ld = si + ld;
  LongDouble sum = operator+(ld, 2);
  cout << static_cast<double>(sum) << endl;
  return 0;
}
