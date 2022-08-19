#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

int main(int argc, char const *argv[]) {
  vector<string> lst;
  auto iter = lst.begin();
  string word;
  while (cin >> word)
    iter = lst.insert(iter, word);
  for(auto i : lst)
    cout << i << " ";
  cout << endl;
  return 0;
}
