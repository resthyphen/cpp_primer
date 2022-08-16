#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;

struct Sales_data;
istream &read(istream &is, Sales_data &item);

struct Sales_data {
  // constructors added
  Sales_data() = default;
  Sales_data(const string &s): bookNo(s) { }
  Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(istream &is){
    read(is, *this); // read will read a transaction from is into this object
  }
  // other members as before
  string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

double Sales_data::avg_price() const {
  if (units_sold)
    return revenue/units_sold;
  else
    return 0;
}

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

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs; // copy data members from lhs into sum
  sum.combine(rhs); // add data members from rhs into sum
  return sum;
}


int main() {
  Sales_data d1;
  Sales_data d2("0-201-78345-X");
  Sales_data d3("0-201-78345-X", 5, 2.5);
  Sales_data d4(std::cin);

  print(std::cout, d1) << std::endl;
  print(std::cout, d2) << std::endl;
  print(std::cout, d3) << std::endl;
  print(std::cout, d4) << std::endl;

  return 0;
}
