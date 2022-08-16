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
using std::for_each;

int main(int argc, char const *argv[]) {
  istream_iterator<int> in_iter(cin), eof;
  /*
  istream_iterator<int> eof;
  while(in_iter != eof)
    vec.push_back(*in_iter++);*/
  vector<int> vec(in_iter, eof);
  for_each(vec.begin(), vec.end(), [](int i)
                                  {cout << i << " "; });
  return 0;
}
