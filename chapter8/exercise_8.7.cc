#include <iostream>
#include <fstream>
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
using std::ifstream;
using std::ofstream;

//class Sales_data;
//istream &read(istream &is, Sales_data &item);

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);

public: // access specifier added
  Sales_data() = default;
  Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(const string &s): bookNo(s) { }
  Sales_data(istream &is){
    read(is, *this);
  }
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

int main(int argc, char const *argv[]) {
  ifstream input(argv[1]);
  ofstream output("file1");
  Sales_data total;
  if (read(input, total)) {  // read the first transaction
    Sales_data trans;      // variable to hold data for the next transaction
    while(read(input, trans)) {    // read the remaining transactions
        if (total.isbn() == trans.isbn()) //  check isbns
            total.combine(trans);  // update the running total
        else {
            print(output, total) << endl; //  print the results
            total = trans;         // process the next book
        }
      }
    print(output, total) << endl;  // print the last transaction
  } else                             // there was no input
        cerr << "No data?!" << endl;
  return 0;
}
