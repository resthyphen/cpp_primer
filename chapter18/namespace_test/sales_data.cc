// ---- sales_data.cc----
// be sure any #includes appear before opening the namespace


#include "sales_data.h"


namespace cplusplus_primer{
  

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
}
