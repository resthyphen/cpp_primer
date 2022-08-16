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
#include <regex>
#include <random>
#include <iomanip>
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
using std::regex;
using std::smatch;
using std::regex_error;
using std::sregex_iterator;
using std::regex_iterator;
using std::cregex_iterator;
using namespace std::regex_constants;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
using std::bernoulli_distribution;
using std::noskipws;
using std::uppercase;
using std::showbase;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::right;
using std::setw;
using std::fstream;


//seek and tell functions will behave differently that in windows(CRLF) and unix(LF)
//two system use different newline character
int main(int argc, char const *argv[]) {
  // open for input and output and preposition file pointers to end-of-file
  // file mode argument see § 8.4 (p. 319)
  fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
  if(!inOut){
    cerr << "Unable to open file!" << endl;
    return EXIT_FAILURE;
  }
  // inOut is opened in ate mode, so it starts out positioned at the end
  auto end_mark = inOut.tellg();    // remember original end-of-file position
  inOut.seekg(0, fstream::beg);     // reposition to the start of the file
  cout << inOut.tellg() << endl;
  size_t cnt = 0;       // accumulator for the byte count
  string line;      // hold each line of input
  // while we haven't hit an error and are still reading the original data
  while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
    cnt += line.size() + 1;         // add 1 to account for the newline
    //cout << line << endl;
    auto mark = inOut.tellg();      // remember the read position
    //cout << mark << endl;
    inOut.seekp(0, fstream::end);       // set the write marker to the end
    inOut << cnt;                       // write the accumulated length
    // print a separator if this is not the last line
    if (mark != end_mark)
      inOut << " ";
    inOut.seekg(mark);            // restore the read position
    cout << inOut.tellg() << endl;
  }

  inOut.seekp(0, fstream::end);      // seek to the end
  inOut << "\n";                      // write a newline at end-of-file
  return 0;
}
