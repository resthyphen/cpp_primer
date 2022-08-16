#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::istringstream;
using std::deque;

int main(int argc, char const *argv[]) {
  string s;
  deque<string> d;
  while(cin >> s)
    d.push_back(s);

  for(auto i = d.cbegin(); i != d.cend(); ++i)
    cout << *i << endl;


  return 0;
}
