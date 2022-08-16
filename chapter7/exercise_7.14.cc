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
  Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
  Sales_data(const string &no) : bookNo(no) {}
  Sales_data(const string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  Sales_data(istream &is) {
    read(is, *this);
  }

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
