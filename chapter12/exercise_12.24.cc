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

int main(int argc, char const *argv[]) {
  string line;
  while (getline(cin, line)) {
    auto n = line.size();
    char *a = new char[line.size() + 1];
    for(size_t i = 0; i != line.size(); ++i)
      *(a + i) = line[i];
    cout << a << endl;
    delete [] a;
  }
  return 0;
}
