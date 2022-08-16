#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <forward_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::forward_list;

int main(int argc, char const *argv[]) {
  vector<char> cv;
  char c;
  while(cin >> c)
    cv.push_back(c);

  string s(cv.begin(), cv.end());
  cout << s << endl;
  return 0;
}
