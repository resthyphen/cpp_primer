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
  for(int (&row)[4]:ia){
    for(int col : row)
      cout << col << '\t';
    cout << endl;
  }
  cout << endl;
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 4; ++j)
      cout << ia[i][j] << '\t';
    cout << endl;
  }
  cout << endl;
  for(int (*i)[4] = ia; i != ia + 3; ++i){
    for(int *j = *i; j != *i + 4; ++j)
      cout << *j << '\t';
    cout << endl;
  }

  return 0;
}
