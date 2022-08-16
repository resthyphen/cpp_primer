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
  ifstream in("afile");
  istream_iterator<string> str_it(in), eof;
  vector<string> v(str_it, eof);
  ostream_iterator<string> out_iter(cout, " ");
  copy(v.begin(), v.end(), out_iter);
  return 0;
}
