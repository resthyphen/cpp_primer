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
  vector<int> v;
  cout << v.at(0);
  cout << v[0];
  cout << v.front();
  cout << *v.begin() << endl;
  
  return 0;
}
