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

class Book {
  friend istream &operator>>(istream &is, Book &b);

public:
  Book() : isbn(""), name(""), author(),
      publish_year(0), publisher(""), version(0) {}

  Book(const std::string &i, const std::string &n,
       const std::vector<std::string> &au,
       unsigned y, const std::string &p = "", unsigned v = 1)
      : isbn(i), name(n), author(au),
        publish_year(y), publisher(p), version(v) {}

  Book(std::istream &is) {
    is >> isbn >> name;
    std::string s;
    is >> s;
    author.push_back(s);
    is >> publish_year >> publisher >> version;
  }

private:
  std::string isbn;
  std::string name;
  std::vector<std::string> author;
  unsigned publish_year;
  std::string publisher;
  unsigned version;
};

istream &operator>>(istream &is, Book &b){
  is >> b.isbn >> b.name;
  std::string s;
  is >> s;
  b.author.push_back(s);
  is >> b.publish_year >> b.publisher >> b.version;
  if (!is)
    b = Book();
  return is;
}

int main(int argc, char const *argv[]) {

  return 0;
}
