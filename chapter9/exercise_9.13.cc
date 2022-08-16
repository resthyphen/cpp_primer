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
  list<int> l{1,2,3,4,5};
  vector<int> v{6,7,8,9,10};
  vector<double> d1(l.begin(), l.end());
  vector<double> d2(v.begin(), v.end());
  for(auto i : d1)
    cout << i << " ";
  cout << endl;

  for(auto i : d2)
    cout << i << " ";
  cout << endl;
  return 0;
}
