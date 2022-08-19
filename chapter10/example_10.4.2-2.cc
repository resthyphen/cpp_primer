#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
#include <iterator>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char const *argv[]) {
  istream_iterator<int> in_iter(cin), eof;
  vector<int> vec(in_iter, eof);
  ostream_iterator<int> out_iter(cout, " ");
  //for (auto e : vec)
    //*out_iter++ = e;
    //out_iter = e;

  copy(vec.begin(), vec.end(), out_iter);
  cout << endl;
  return 0;
}
