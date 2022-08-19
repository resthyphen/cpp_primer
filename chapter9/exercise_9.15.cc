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
  vector<int> v1{1,2,3,4,5};
  vector<int> v2{6,7,8,9,10};
  cout << (v1 == v2) << endl;
  return 0;
}
