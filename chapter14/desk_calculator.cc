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

int add(int i, int j) {
  return i + j;
}

auto mod = [](int i, int j) { return i % j; };

struct divide {
  int operator()(int denominator, int divisor) {
    return denominator / divisor;
  }
};

map<string, function<int(int, int)>> binops = {
  {"+", add}, // function pointer
  {"-", std::minus<int>()}, // library function object
  {"/", divide()}, // user-defined function object
  {"*", [](int i, int j) { return i * j; }}, // unnamed lambda
  {"%", mod}
};

int main(int argc, char const *argv[]) {

  cout << binops["+"](10, 5) << endl;
  cout << binops["-"](10, 5)  << endl;
  cout << binops["*"](10, 5)  << endl;
  cout << binops["/"](10, 5)  << endl;
  cout << binops["%"](10, 5)  << endl;
  return 0;
}
