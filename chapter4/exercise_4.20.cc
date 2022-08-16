#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<string> vec{"a", "an", "the"};
  auto iter = vec.begin();
  cout << *iter++ << endl;
  //cout << (*iter)++ << endl;
  cout << *iter << endl;
  cout << vec[1] << endl;
  cout << iter->empty() << endl;
  cout << iter++->empty() << endl;
  return 0;
}
