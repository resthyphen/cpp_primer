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
  forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
  auto prev = flst.before_begin(); // denotes element "off the start" of flst
  auto curr = flst.begin(); // denotes the first element in flst
  while (curr != flst.end()) { // while there are still elements to process
    if (*curr % 2) // if the element is odd
      curr = flst.erase_after(prev); // erase it and move curr
    else {
      prev = curr; // move the iterators to denote the next
      ++curr; // element and one before the nextelement
    }
  }
  for(auto i : flst)
    cout << i << endl;
  return 0;
}
