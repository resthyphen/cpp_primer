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
  forward_list<int> fi = {0,1,2,3,4,5,6,7,8,9};
  auto prev = fi.before_begin();
  auto curr = fi.begin();
  while(curr != fi.end())
    if(*curr % 2){
      curr = fi.insert_after(curr, *curr);
      prev = curr++;
    }
    else
      curr = fi.erase_after(prev);

  for(auto i : fi)
    cout << i << " ";
  cout << endl;
  return 0;
}
