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
  Sales_data(const double &d): revenue(d) { }
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

  Sales_data& operator=(const string &s){
    bookNo = s;
    return *this;
  }

  Sales_data& operator+=(const Sales_data &rhs){
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue; // the members of ''this'' object
    return *this;
  }

  explicit operator string() const {
    return bookNo;
  }

  explicit operator double() const {
    return revenue;
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



int main(int argc, char const *argv[]) {
  Sales_data s1;
  s1 = "0-201-78345-X";
  string str = "sdfds";
  string book = s1;
  cout << book  << endl;
  string s = s1 + str;
  cout << s << endl;
  Sales_data s2;
  // double d = 2.3;
  // s2 = 2.3;
  // double i = 4.2;
  // cout << s2 << endl;
  s2 = 2.3;
  // double d = s2;
  // double j = 4.2;
  double d = 2.2 + s1;
  cout << d << endl;
  return 0;
}
