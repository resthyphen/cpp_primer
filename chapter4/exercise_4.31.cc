#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> ivec(10);
  vector<int>::size_type cnt = ivec.size();
  for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
  for(auto i : ivec)
    cout << i << " ";
  cout << endl;
  return 0;
}
