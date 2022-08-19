#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  string word;
  unsigned ffCnt = 0;
  unsigned flCnt = 0;
  unsigned fiCnt = 0;
  while(cin >> word){
    for(int i = 0; i != word.size(); ++i)
      if(word[i] == 'f' && i + 1 < word.size()){
        switch (word[i+1]) {
          case 'f':
            ++ffCnt;
            break;
          case 'l':
            ++flCnt;
            break;
          case 'i':
            ++fiCnt;
            break;
        }
      }
  }
  cout << "ff: " << ffCnt << '\n'
       << "fl: " << flCnt << '\n'
       << "fi: " << fiCnt << endl;
  return 0;
}
