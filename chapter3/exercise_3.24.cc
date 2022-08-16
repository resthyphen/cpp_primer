#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> v{1,2,3,4,5,6,7,8,9};
  for(auto i = v.begin(); i != v.end(); ++i)
    *i *= *i;
  for(auto i = v.begin(); i != v.end(); ++i)
    cout << *i << " ";
  cout << endl;

  return 0;
}
