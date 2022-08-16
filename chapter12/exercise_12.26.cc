#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
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
using std::out_of_range;
using std::exception;
using std::allocator;

int main(int argc, char const *argv[]) {
  string::size_type n = 10;
  allocator<string> alloc;
  auto const p = alloc.allocate(n);
  string s;
  string *q = p;
  while(cin >> s && q != p + n)
    //*q++ = s;
    alloc.construct(q++, s);

  const size_t size = q - p;
  string *i = p;
  while(i != q){
    cout << *i << endl;
    ++i;
  }
  //delete [] p;
  //cout << *(--q) << endl;
  while (q != p)
    alloc.destroy(--q);
  alloc.deallocate(p, n);
  return 0;
}
