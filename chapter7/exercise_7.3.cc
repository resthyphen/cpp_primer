#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

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

int main(int argc, char const *argv[]) {
  Sales_data total;
  double price;
  if(cin >> total.bookNo >> total.units_sold >> price){
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if(total.isbn() == trans.isbn())
        total.combine(trans);
      else{
        cout << total.bookNo <<" "
             << total.units_sold <<" "
             << total.revenue << endl;
      }
    }
    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << std::endl;
  }else{
    cerr << "No data" << endl;
  }

  return 0;
}
