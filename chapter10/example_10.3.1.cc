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

bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

int main(int argc, char const *argv[]) {
  vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
  elimDups(words);
  stable_sort(words.begin(), words.end(), isShorter);
  for (const auto &s : words) // no need to copy the strings
    cout << s << " ";
  cout << endl;
  return 0;
}
