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
#include <numeric>
#include <bitset>
#include <regex>
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
using std::tuple;
using std::make_tuple;
using std::get;
using std::make_pair;
using std::bitset;
using std::bitset;
using std::regex;
using std::smatch;
using std::regex_error;
using std::fstream;
using std::flush;

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

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
  return lhs.isbn() < rhs.isbn();
}

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator> matches;

vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book){
  vector<matches> ret;
  for (auto it = files.cbegin(); it != files.cend(); ++it){
    // find the range of Sales_data that have the same ISBN
    auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second) // this store had sales
// remember the index of this store and the matching range
      ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
  }
  return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files){
  string s;
  while (in >> s) {
    auto trans = findBook(files, s);
    if(trans.empty()){
      cout << s << " not found in any stores" << endl;
      continue;
    }
    for(const auto &store : trans)
      os << "store " << get<0>(store) << "sales: "
         << accumulate(get<1>(store), get<2>(store), Sales_data(s))
         << endl;
  }
}



int  main(int argc, char const *argv[]) {
  fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
  string line;
  inOut.seekg(0, fstream::beg);
  cout << flush;
  while(getline(inOut, line)){
    cout << inOut.tellg() - 4 << endl;
    cout << line << endl;
  }
  return 0;
}
