#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <functional>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using namespace std::placeholders;
using std::forward_list;


int main(int argc, char const *argv[]) {
  list<int> lst{1,2,3,4};
  list<int> lst2{5,6,7,8};
  forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
  forward_list<int> flst2{23,16,27,11};
  //auto iter = lst2.begin();
  //for(size_t i = 0; i < 2; ++i)
  //  ++iter;                   
  //cout << *iter << endl;
  //flst.splice_after(iter, flst2);
  //flst.splice_after(flst.begin(), flst2, iter);
  //lst.splice(lst.begin(), lst, iter);
  //lst.splice(lst.begin(), lst2, lst2.begin(), lst2.end());
  flst.splice_after(flst.begin(), flst2, flst2.begin(), flst2.end());
  for(auto i : flst)
    cout << i << " ";
  cout << endl;
  for(auto i : flst2)
    cout << i << " ";
  cout << endl;
}
