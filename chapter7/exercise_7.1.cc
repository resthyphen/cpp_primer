#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main(int argc, char const *argv[]) {
  Sales_data total;
  double price;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;                             // variable to hold the running sum
        // read and process the remaining transactions
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
          trans.revenue = trans.units_sold * price;// if we're still processing the same book
          if (total.bookNo == trans.bookNo){
            total.units_sold += trans.units_sold;
            total.revenue += trans.revenue; // update the running total
          }
          else {                // print results for the previous book
            std::cout << total.bookNo << " "
                << total.units_sold << " "
                << total.revenue << std::endl;
            total.bookNo = trans.bookNo;
            total.units_sold = trans.units_sold;
            total.revenue = trans.revenue; // total now refers to the next book
          }
    }
    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << std::endl; // print the last transaction
    } else {        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
  return 0;
}
