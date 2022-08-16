#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
#include <utility>
#include <functional>
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
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::plus;
using std::negate;
using std::less;
using std::function;

class Foo{
public:
  Foo() = default;
  Foo(vector<int> &v): data(v){};
  Foo(const Foo&);
  Foo &operator=(const Foo&);
  Foo(Foo&&);
  Foo &operator=(Foo &&);
  Foo sorted() &&;        // may run on modifiable rvalues
  Foo sorted() const &;   // may run on any kind of Foo
  vector<int> &getVec() {
    return this->data;
  }

private:
  vector<int> data;
};

Foo::Foo(const Foo &f) : data(f.data){
  cout << "Foo(const Foo&)" << endl;
}

Foo& Foo::operator=(const Foo &rhs){
  data = rhs.data;
  cout << "Foo &operator=(const Foo&)" << endl;
  return *this;
}

Foo::Foo(Foo &&f) : data(f.data){
  cout << "Foo(Foo&&)" << endl;
}

Foo& Foo::operator=(Foo &&rhs){
  if(this != &rhs)
    data = rhs.data;
  cout << "Foo &operator=(Foo &&)" << endl;
  return *this;
}

Foo Foo::sorted() &&
{
  sort(data.begin(), data.end());
  cout << "Foo sorted() &&" << endl;
  return *this;
}

// Foo Foo::sorted() const & {
//   Foo ret(*this);           //ret is lvalue
//   return ret.sorted();
// }

Foo Foo::sorted() const & {
  return Foo(*this).sorted();           //Foo(*this) is rvalue
}


void fcn3()
{
  size_t v1 = 42; // local variable
  // f can change the value of the variables it captures
  auto f = [v1] () mutable{ return ++v1; };
  v1 = 0;
  auto j = f(); // j is 43
  cout << j << endl;
}

void fcn4()
{
  size_t v1 = 42; // local variable
  // v1 is a reference to a non const variable
  // we can change that variable through the reference inside f2
  auto f2 = [&v1] { return ++v1; };
  v1 = 0;
  auto j = f2(); // j is 1
  cout << v1 << endl;
}


int add(int i, int j) {
  return i + j;
}

auto mod = [](int i, int j) { return i % j; };

struct d {
  int operator()(int denominator, int divisor) {
    return denominator / divisor;
  }
};

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);

public: // access specifier added
  Sales_data() = default;           //default constructor
  //Sales_data(std::string s = ""): bookNo(s) { }       //default constructor
  Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n) { }
  explicit Sales_data(const string &s): bookNo(s) { }
  explicit Sales_data(istream &is){
    read(is, *this);
  }

  Sales_data(const Sales_data &orig):bookNo(orig.bookNo), units_sold(orig.units_sold),revenue(orig.revenue){}

  Sales_data& operator=(const Sales_data &rhs){
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
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


int main(int argc, char const *argv[]) {
  Sales_data s1("0-201-78345-X");
  s1.combine(cin);
  print(cout, s1);
  return 0;
}
