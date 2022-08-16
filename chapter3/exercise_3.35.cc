#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main(int argc, char const *argv[]) {
  int ia[] = {0,2,4,6,8};
  //for(auto &i : ia)
  //  i = 0;
  int *b = begin(ia), *e = end(ia);
  for(; b != e; ++b)
    *b = 0;
  for(auto i : ia)
    cout << i << " ";
  cout << endl;
  return 0;
}
