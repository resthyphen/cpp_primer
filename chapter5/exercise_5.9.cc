#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  unsigned vowelCnt = 0;
  char ch;
  while(cin >> ch){
    if(ch == 'a')
      ++vowelCnt;
    if(ch == 'e')
      ++vowelCnt;
    if(ch == 'i')
      ++vowelCnt;
    if(ch == 'o')
      ++vowelCnt;
    if(ch == 'u')
      ++vowelCnt;
  }
  cout << "vowel: " << vowelCnt << endl;

  return 0;
}
