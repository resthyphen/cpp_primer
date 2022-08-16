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

class numbered {
public:
  numbered() : mysn(++sn) {}
  numbered(const numbered &) : mysn(++sn) {}
  int mysn;

private:
  static int sn;

};

int numbered::sn = 0;

void f(const numbered &s) {
  cout << s.mysn << endl;
}

int main(int argc, char const *argv[]) {
  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
  numbered d;
  f(d);
  return 0;
}
