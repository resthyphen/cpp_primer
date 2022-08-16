#include <iostream>
#include <vector>
#include <string>
#include <list>
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

int main(int argc, char const *argv[]) {
  vector<string> v{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

  list<string> lst;
  sort(v.begin(), v.end());
  auto end_unique = unique(v.begin(), v.end());
  v.erase(end_unique, v.end());
  for(auto &i : v)
    cout << i << " ";
  cout << endl;
  unique_copy(v.cbegin(), v.cend(), front_inserter(lst));
  for(auto &i : lst)
    cout << i << " ";
  cout << endl;
  return 0;
}
