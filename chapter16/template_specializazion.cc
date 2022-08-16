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
using std::begin;
using std::end;
using std::ostringstream;

template <typename T>
int compare(const T &v1, const T &v2){
  cout << "compare(const T &v1, const T &v2)" << endl;
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

// special version of compare to handle pointers to character arrays
template <>
int compare(const char* const &p1, const char* const &p2){
  cout << "compare(const char* const &p1, const char* const &p2)" << endl;
  return strcmp(p1, p2);
}

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
  cout << "compare(const char (&p1)[N], const char (&p2)[M])" << endl;
  return strcmp(p1, p2);
}


int main(int argc, char const *argv[]) {
  const char *p1 = "hi", *p2 = "mom";
  cout << compare("niwer", "mom") << endl;
  cout << compare(p1, p2) << endl;
  return 0;
}
