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
using std::ifstream;
using std::ofstream;
using std::cend;
using std::to_string;

int main(int argc, char const *argv[]) {
  ifstream in(argv[1]);
  istream_iterator<int> in_iter(in), eof;
  vector<int> v(in_iter, eof);
  for_each(v.cbegin(), v.cend(), [](int i){ cout << i << " "; });
  cout << endl;
  ofstream out1(argv[2]);
  ostream_iterator<int> out1_iter(out1, " ");
  ofstream out2(argv[3]);
  ostream_iterator<int> out2_iter(out2, " ");
  for(auto i : v)
    if(i % 2 != 0)
      out1_iter = i;
    else
      out2_iter = i;
  in.close();
  out1.close();
  out2.close();

  ifstream in2(argv[2]);
  int i;
  while(in2 >> i)
    cout << i << " ";
  cout << endl;
  in2.close();

  ifstream in3(argv[3]);
  while(in3 >> i)
    cout << i << " ";
  cout << endl;
  in3.close();

  return 0;
}
