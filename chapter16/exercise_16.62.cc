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

class Sales_data;
template <class T> class hash; // needed for the friend declaration

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &operator>>(istream &is, Sales_data &item);
friend ostream &operator<<(ostream &os, const Sales_data &item);
friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
friend size_t hasher(const Sales_data &sd);
friend class std::hash<Sales_data>;

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

namespace std {
template <> // we're defining a specialization with
struct hash<Sales_data> { // the template parameter of Sales_data
  // the type used to hash an unordered container must define these types
  typedef size_t result_type;
  typedef Sales_data argument_type; // by default, this type needs ==
  size_t operator()(const Sales_data& s) const;
  // our class uses synthesized copy control and default constructor
};
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
  return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^
  hash<double>()(s.revenue);
}
} // close the std namespace; note: no semicolon after the close curly

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

size_t hasher(const Sales_data &sd){
  return hash<string>()(sd.isbn());
}

int main(int argc, char const *argv[]) {
  Sales_data sd("0-201-78345-X", 3, 20.00);
  Sales_data sd2("0-201-78345-X", 2, 25.00);
  Sales_data sd3("0-201-70353-X", 4, 24.99);
  Sales_data sd4("0-201-70353-X", 4, 24.99);
  Sales_data sd5("0-201-70354-X", 4, 20.99);
  Sales_data sd6("0-201-78345-X", 2, 20.00);
  Sales_data sd7("0-201-78345-X", 3, 20.00);
  cout << hasher(sd) << endl;
  unordered_multiset<Sales_data> SDset;
  SDset.insert(sd);
  SDset.insert(sd2);
  SDset.insert(sd3);
  SDset.insert(sd4);
  SDset.insert(sd5);
  SDset.insert(sd6);
  SDset.insert(sd7);
  for(auto i : SDset)
    cout << i.isbn() << ": " << hash<Sales_data>()(i) << endl;

  cout << SDset.bucket_count() << endl;
  cout << SDset.max_bucket_count() << endl;
  cout << SDset.bucket_size(1) << endl;
  cout << *(SDset.find(sd4)) << endl;
  return 0;
}
