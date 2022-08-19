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
  vector<int> v = {0,1,2,3,4,5,6,7,8,9};
  auto begin = v.begin(),end = v.end(); // bad idea, saving the value of the end iterator
  while (begin != v.end()) {
    // do some processing
    // insert the new value and reassign begin, which otherwise would be invalid
    ++begin; // advance begin because we want to insert after this element
    begin = v.insert(begin, 42); // insert the new value
    ++begin; // advance begin past the element we just added
}
  for(auto i : v)
    cout << i << " ";
  cout << endl;
  return 0;
}
