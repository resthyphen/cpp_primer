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
  vector<int> iv{1,2,3,4,5,6};
  for(auto i : iv)
    cout << i << " ";
  cout << endl;
  vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
  int some_val = 3;
  //iv.insert(iter, 2 * some_val);
  while (iter != iv.begin() + iv.size()/2){
    if (*iter == some_val){
      iter = iv.insert(iter, 2 * some_val);
      //++iter;    after comment this, program will be right for remaining code?
    }
    //++iter;
    //iter = iv.insert(iter, 6);
    ++iter;
  }
  for(auto i : iv)
    cout << i << " ";
  cout << endl;
  return 0;
}
