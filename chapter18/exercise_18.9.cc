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
using std::overflow_error;

// hypothetical exception classes for a bookstore application
class out_of_stock: public std::runtime_error {
public:
  explicit out_of_stock(const std::string &s):
  runtime_error(s) { }
};

class isbn_mismatch: public std::logic_error {
public:
  explicit isbn_mismatch(const std::string &s):
  std::logic_error(s) { }
  isbn_mismatch(const std::string &s,
  const std::string &lhs, const std::string &rhs):
  std::logic_error(s), left(lhs), right(rhs) { }
  const std::string left, right;
};


class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &operator>>(istream &is, Sales_data &item);
friend ostream &operator<<(ostream &os, const Sales_data &item);
friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

public: // access specifier added
  Sales_data() = default;           //default constructor
  //Sales_data(std::string s = ""): bookNo(s) { }       //default constructor
  Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(const string &s): bookNo(s) { }
  Sales_data(istream &is){
    read(is, *this);
  }

  Sales_data(const Sales_data &orig):bookNo(orig.bookNo), units_sold(orig.units_sold),revenue(orig.revenue){}

  Sales_data& operator=(const Sales_data &rhs){
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
  }

  Sales_data& operator+=(const Sales_data &rhs){
    if (isbn() != rhs.isbn())
      throw isbn_mismatch("wrong isbns",isbn(), rhs.isbn());
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue; // the members of ''this'' object
    return *this;
  }

  ~Sales_data() { }
  string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data&);

private: // access specifier added
  double avg_price() const{
    return units_sold ? revenue/units_sold : 0;
  }
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold; // add the members of rhs into
  revenue += rhs.revenue; // the members of ''this'' object
  return *this; // return the object on which the function was called
}

istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)  //lhs:left hand side  rhs:itright hand side
{
  Sales_data sum = lhs; // copy data members from lhs into sum
  sum.combine(rhs); // add data members from rhs into sum
  return sum;
}

/*
Sales_data::Sales_data(istream &is)
{
  read(is, *this); // read will read a transaction from is into this object
}
*/

istream &operator>>(istream &is, Sales_data &item){
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  if(is)
    item.revenue = price * item.units_sold;
  else
    item = Sales_data();
  return is;
}

ostream &operator<<(ostream &os, const Sales_data &item){
  os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
  return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs){
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs){
  return lhs.isbn() == rhs.isbn() &&
  lhs.units_sold == rhs.units_sold &&
  lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs){
  return !(lhs == rhs);
}

inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{ return lhs.isbn() == rhs.isbn(); }

int main(int argc, char const *argv[]) {
  // use the hypothetical bookstore exceptions
  Sales_data item1, item2, sum;
  while (cin >> item1 >> item2) {
    // try {
    //   sum = item1 + item2;      // read two transactions
    //   // calculate their sum
    //   cout << sum << endl;
    // }catch(const exception &e){
    //    // cerr << e.what() << ": left isbn(" << e.left
    //    //       << ") right isbn(" << e.right << ")" << endl;
    //   cerr << e.what() << endl;
    // }
    sum = item1 + item2;
    cout << sum << endl;
  }
  return 0;
}
