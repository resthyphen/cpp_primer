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
  constexpr size_t rowCnt = 3, colCnt = 4;
  int ia[rowCnt][colCnt]; // 12 uninitialized elements
  // for each row
/*  for (size_t i = 0; i != rowCnt; ++i) {
    // for each column within the row
    for (size_t j = 0; j != colCnt; ++j) {
// assign the element's positional index as its value
      ia[i][j] = i * colCnt + j;
    }
  } */
  size_t cnt = 0;
  for (auto &row : ia) // for every element in the outer array
    for (auto &col : row) { // for every element in the inner array
      col = cnt; // give this element the next value
      ++cnt; // increment cnt
    }

/*  for (auto p = begin(ia); p != end(ia); ++p) {
  // q points to the first element in an inner array
    for (auto q = begin(*p); q != end(*p); ++q)
      cout << *q << ' '; // prints the int value to which q points
    cout << endl;
  } */

  for(const auto row : ia){
    for(auto col : row)
      cout << col << " ";
    cout << endl;
  }
  return 0;
}
