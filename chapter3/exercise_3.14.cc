#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> v;
  int i;
  while (cin >> i) {
    v.push_back(i);
  }
  //cout << v << endl;
  
  return 0;
}
