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

bool more_than_five(const string &s){
  return s.size() >= 5;
}

int main(int argc, char const *argv[]) {
  vector<string> words;
  string s;
  while(cin >> s){
    words.push_back(s);
  }
  partition(words.begin(), words.end(), more_than_five);
  auto iter = words.cbegin();
  while(iter != words.cend()){
    cout << *iter << endl;
    ++iter;
  }
  return 0;
}
