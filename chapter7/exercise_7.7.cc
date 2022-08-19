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

struct Sales_data {
  // new members: operations on Sales_data objects
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
  // data members are unchanged from § 2.6.1 (p. 72)
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

int main(int argc, char const *argv[]) {
  Sales_data total;         // variable to hold the running sum
  if (read(cin, total))  {  // read the first transaction
    Sales_data trans;     // variable to hold data for the next transaction
    while(read(cin, trans)) {      //  read the remaining transactions
        if (total.isbn() == trans.isbn())   // check the isbns
            total.combine(trans);  // update the running total
        else {
            print(cout, total) << endl;  // print the results
            total = trans;               // process the next book
        }
      }
      print(cout, total) << endl;          // print the last transaction
    } else {                                 // there was no input
        cerr << "No data?!" << endl;         // notify the user
      }
  return 0;
}
