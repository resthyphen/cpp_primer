#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

void elimDups(vector<string> &words){
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void elimDups2(vector<int> &v){
  sort(v.begin(), v.end());
  auto end_unique = unique(v.begin(), v.end());
  v.erase(end_unique, v.end());
}

int main(int argc, char const *argv[]) {
  vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  vector<int> v{1,2,3, 4, 6, 8, 3, 2, 1, 2, 4, 3, 3, 6, 8, 8};
  elimDups(words);
  elimDups2(v);
  auto iter = words.cbegin();
  while(iter != words.cend()){
    cout << *iter << " " ;
    ++iter;
  }
  cout << endl;
  auto iterv = v.cbegin();
  while(iterv != v.cend()){
    cout << *iterv << " " ;
    ++iterv;
  }
  cout << endl;
  return 0;
}
