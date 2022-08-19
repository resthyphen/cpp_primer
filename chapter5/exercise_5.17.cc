#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<int> v1{0,1,1,2};
  vector<int> v2{0, 1, 1, 2, 3, 5,8};
  auto sz = v1.size();
  int i;
  for(i = 0; i != sz; ++i){
    if(v1[i] != v2[i])
      break;
  }
  if(i == sz)
    cout << "v1 is prefix of v2" << endl;

  return 0;
}
