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
using std::greater;
using std::not_equal_to;
using std::multiplies;
using std::divides;
using std::modulus;
using namespace std::placeholders;
using std::function;


class Book {
public:
  Book() : isbn(""), name(""), author(""),
      publish_year(0), publisher(""), version(0) {}

  Book(const std::string &i, const std::string &n,
       const string &au,
       unsigned y, const std::string &p = "", unsigned v = 1)
      : isbn(i), name(n), author(au),
        publish_year(y), publisher(p), version(v) {}

  Book(std::istream &is) {
    is >> isbn >> name;
    is >> author;
    is >> publish_year >> publisher >> version;
  }

  operator bool() const {
    return isbn != "" && name != "";
  }

private:
  std::string isbn;
  std::string name;
  string author;
  unsigned publish_year;
  std::string publisher;
  unsigned version;
};



int main(int argc, char const *argv[]) {
  Book book;
  bool b = book;
  cout << b << endl;
  return 0;
}
