#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
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
using std::list;

int main(int argc, char const *argv[]) {
  list<int> lst{1,23,4, 0, 6, 3, 4, 0, 8};
  auto rzero = find(lst.crbegin(), lst.crend(), 0);
  
  return 0;
}
