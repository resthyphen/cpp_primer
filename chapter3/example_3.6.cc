#include<iostream>
#include<vector>
#include<cstring>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main(int argc, char const *argv[]) {
  int ia[3][4] = {    // three elements; each element is an array of size 4
    {0, 1, 2, 3},   // initializers for the row indexed by 0
    {4, 5, 6, 7},   // initializers for the row indexed by 1
    {8, 9, 10, 11}  // initializers for the row indexed by 2
  };
  for (auto p = ia; p != ia + 3; ++p) {
    // q points to the first element of an array of four ints; that is, q points to an int
    for (auto q = *p; q != *p + 4; ++q)
      cout << *q << ' ';
    cout << endl;
  }

  // p points to the first array in ia
  for (auto p = begin(ia); p != end(ia); ++p) {
  // q points to the first element in an inner array
    for (auto q = begin(*p); q != end(*p); ++q)
      cout << *q << ' '; // prints the int value to which q points
    cout << endl;
  }

  return 0;
}
