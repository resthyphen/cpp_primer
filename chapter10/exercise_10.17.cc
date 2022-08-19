#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::istream;

class Sales_data {
  friend istream &read(istream&, Sales_data&);

public: // access specifier added
  Sales_data() = default;
  Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(const string &s): bookNo(s) { }
  Sales_data(istream &is){
    read(is, *this);
  }
  string isbn() const { return bookNo; }

private: // access specifier added
  double avg_price() const{
    return units_sold ? revenue/units_sold : 0;
  }
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

int main(int argc, char const *argv[]) {
  vector<Sales_data> v;
  while(cin){
    Sales_data s(cin);
    v.push_back(s);
  }
  sort(v.begin(), v.end(), [](const Sales_data &lhs, const Sales_data &rhs){
                                return lhs.isbn() < rhs.isbn();
                              });
  auto iter = v.cbegin();
  while(iter != v.cend()){
    cout << (*iter).isbn() << endl;
    ++iter;
  }
  return 0;
}
