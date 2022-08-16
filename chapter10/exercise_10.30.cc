#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
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

int main(int argc, char const *argv[]) {
  istream_iterator<int> in_iter(cin), eof;
  vector<int> v(in_iter, eof);
  sort(v.begin(), v.end());
  ostream_iterator<int> out_iter(cout, " ");
  copy(v.begin(), v.end(), out_iter);
  return 0;
}
