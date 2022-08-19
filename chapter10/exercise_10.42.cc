#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <functional>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using namespace std::placeholders;
using std::forward_list;

void elimDups(list<string> &words){
  words.sort();
  words.unique();
}

int main(int argc, char const *argv[]) {
  list<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  elimDups(words);
  for(auto i : words)
    cout << i << " ";
  cout << endl;
  return 0;
}
