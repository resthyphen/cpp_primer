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
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
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
using std::hash;
using std::unordered_multiset;
using std::tuple;
using std::make_tuple;
using std::get;
using std::make_pair;
using std::bitset;

int main(int argc, char const *argv[]) {
  bitset<32> bitvec(1U);
  bitset<32> bitvec4("1100");
  cout << bitvec4 << endl;
  bitset<31> bitvec3(~0UL);
  cout << bitvec3 << endl;
  auto ulong =  bitvec3.to_ulong();
  cout << "ulong = " << ulong << endl;
  bitset<16> bits;
  // cin >> bits;    // read up to 16 1 or 0 characters from cin
  // cout << "bits: " << bits << endl; // print what we just read
  cout << (1ul << 27) << endl;
  return 0;
}
