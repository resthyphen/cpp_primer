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

template<typename T, unsigned N>
ostream &print(ostream &os, const T (&a)[N])
{
  for(size_t i = 0; i != N; ++i)
    os << a[i] << endl;
  return os;
}

int main(int argc, char const *argv[]) {
  int a1[3] = {0,1,2};
  string a2[3] =  {"hi", "bye"};
  print(cout,a1);
  print(cout,a2);
  return 0;
}
