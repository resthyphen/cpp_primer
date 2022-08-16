#include <iostream>
#include <vector>
#include <string>
#include <list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;

int main(int argc, char const *argv[]) {
  list<char*> l = {"a", "an", "the"};       //C-style character strings
  vector<string> vs;
  vs.assign(l.cbegin(), l.cend());
  for(auto i : vs)
    cout << i << endl;
  return 0;
}
