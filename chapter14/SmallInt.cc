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

class SmallInt {
friend SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs);

public:
  SmallInt(int i = 0): val(i){ if (i < 0 || i > 255)
    throw std::out_of_range("Bad SmallInt value");
  }

  operator int() const { return val; }

private:
  std::size_t val;
};

SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs){
  cout << "SmallInt operator+" << endl;
  SmallInt sum(lhs);
  sum = sum + rhs;
  return sum;
}

int main(int argc, char const *argv[]) {
  SmallInt si;
  si = 4;  //implicitly converts 4 to SmallInt then calls SmallInt::operator=
  //int n = si + 3; //implicitly converts si to int followed by integer addition
  //cout << n << endl;
  si = 3.14;
  cout << si << endl;
  int i = 1;
  cout << (1 << 27) << endl;

  SmallInt s1, s2;
  SmallInt s3 = s1 + s2;
  cout << s3 << endl;
  //int i = s3 + 1;
  return 0;
}
