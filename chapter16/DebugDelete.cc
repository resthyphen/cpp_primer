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
using std::unique_ptr;

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr): os(s) { }
  // as with any function template, the type of T is deduced by the compiler
  template <typename T> void operator()(T *p) const{
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};

int main(int argc, char const *argv[]) {
  double* p = new double;
  DebugDelete d; // an object that can act like a delete expression
  //d(p);   // calls DebugDelete::operator()(double*), which deletes p
  int* ip = new int;
  // calls operator()(int*) on a temporary DebugDelete object
  // DebugDelete()(ip);
  // destroying the the object to which p points
  // instantiates DebugDelete::operator()<int>(int *)
  unique_ptr<int, DebugDelete> p(new int, DebugDelete());
  // destroying the the object to which sp points
  // instantiates DebugDelete::operator()<string>(string*)
  unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

  return 0;
}
