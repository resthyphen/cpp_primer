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
  vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
  auto iter = vi.begin();
  while (iter != vi.end()){
    if (*iter % 2)
      iter = vi.insert(iter, *iter);
    ++iter;
  }
  for(auto i : vi)
    cout << i << " ";
  cout << endl;
  return 0;
}
