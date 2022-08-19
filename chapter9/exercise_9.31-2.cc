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
  list<int> lst{0,1,2,3,4,5,6,7,8,9};
  auto iter = lst.begin();
  while(iter != lst.end())
    if(*iter % 2){
      iter = lst.insert(iter, *iter);
      ++iter;
      ++iter;
    }
    else
      iter = lst.erase(iter);

  for(auto i : lst)
    cout << i << " ";
  cout << endl;

  return 0;
}
