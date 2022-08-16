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

class Quote {
public:
  Quote() = default; // = default see § 7.1.4 (p. 264)
  Quote(const std::string &book, double sales_price):
  bookNo(book), price(sales_price) { }
  std::string isbn() const { return bookNo; }
  // returns the total sales price for the specified number of items
  // derived classes will override and apply different discount algorithms
  virtual double net_price(std::size_t n) const
  { return n * price; }

  virtual ~Quote() = default; // dynamic binding for the destructor

  Quote(const Quote &orig) : bookNo(orig.bookNo), price(orig.price){
    cout << "Quote(const Quote &orig)" << endl;
  }
  Quote& operator=(const Quote &rhs){
    cout << "Quote& operator=(const Quote &rhs)" << endl;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
  }

  Quote(Quote &&q) : bookNo(q.bookNo), price(q.price){
    cout << "Quote(Quote &&q)" << endl;
  }

  Quote& operator=(Quote &&rhs){
    cout << "Quote& operator=(Quote &&rhs)" << endl;
    if(this != &rhs){
      bookNo = rhs.bookNo;
      price = rhs.price;
    }
    return *this;
  }

private:
  std::string bookNo; // ISBN number of this item

protected:
  double price = 0.0; // normal, undiscounted price
};

class Disc_quote : public Quote {   //Abstract Base Class
public:
  Disc_quote() = default;
  Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
  Quote(book, price), quantity(qty), discount(disc) { }
  double net_price(std::size_t) const = 0;

  Disc_quote(const Disc_quote &d): Quote(d), quantity(d.quantity), discount(d.discount){
    cout << "Disc_quote(const Disc_quote &d)" << endl;
  }

  Disc_quote& operator=(const Disc_quote &rhs){
    cout << "Disc_quote& operator=(const Disc_quote &rhs)" << endl;
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
  }

  Disc_quote(Disc_quote &&d): Quote(std::move(d)), quantity(d.quantity), discount(d.discount){
    cout << "Disc_quote(Disc_quote &&d)" << endl;
  }

  Disc_quote& operator=(Disc_quote &&rhs){
    cout << "Disc_quote& operator=(Disc_quote &&rhs)" << endl;
    if(this != &rhs){
      Quote::operator=(std::move(rhs));
      quantity = rhs.quantity;
      discount = rhs.discount;
    }
    return *this;
  }

protected:
  std::size_t quantity = 0; // purchase size for the discount to apply
  double discount = 0.0; // fractional discount to apply
};

class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote

public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) :
    Disc_quote(book, price, qty, disc){ }
// overrides the base version in order to implement the bulk purchase discount policy
  double net_price(std::size_t) const override;

  Bulk_quote(const Bulk_quote &b): Disc_quote(b){
    cout << "Bulk_quote(const Bulk_quote &b)" << endl;
  }
  Bulk_quote& operator=(const Bulk_quote &rhs){
    cout << "Bulk_quote& operator=(const Bulk_quote &rhs)" << endl;
    Disc_quote::operator=(rhs);
    return *this;
  }

  Bulk_quote(Bulk_quote &&b):Disc_quote(std::move(b)){
    cout << "Bulk_quote(Bulk_quote &&b)" << endl;
  }
  Bulk_quote& operator=(Bulk_quote &&rhs){
    cout << "Bulk_quote& operator=(Bulk_quote &&rhs)" << endl;
    if(this != &rhs)
      Disc_quote::operator=(std::move(rhs));
    return *this;
  }
};


double Bulk_quote::net_price(size_t cnt) const
{
  if (cnt >= quantity)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;

}


// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n){
// depending on the type of the object bound to the item parameter
// calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main(int argc, char const *argv[]) {
  Bulk_quote d1("0-201-82470-1", 20, 5, 0.19);
  cout << d1.net_price(6) << endl;
  cout << endl;
  Bulk_quote d2;
  d2 = d1;
  cout << endl;
  Bulk_quote d3("0-201-82470-2", 50, 5, 0.19);
  Bulk_quote d4(std::move(d3));
  Bulk_quote d5;
  d5 = std::move(d4);
  cout << endl;
  print_total(cout, d1, 6);
  print_total(cout, d3, 6);
  print_total(cout, d4, 6);
  print_total(cout, d5, 6);
  return 0;
}
