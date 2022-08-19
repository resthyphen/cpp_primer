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
using std::begin;
using std::end;

int main(int argc, char const *argv[]) {
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  vector<int> v(begin(ia), end(ia));
  list<int> lst(begin(ia), end(ia));
  cout << "v: " ;
  for(auto i : v)
    cout << i << " ";
  cout << endl;
  cout << "lst: " ;
  for(auto i : lst)
    cout << i << " ";
  cout << endl;

  auto iter1 = lst.begin();
  while(iter1 != lst.end())
    if(*iter1 % 2)
      iter1 = lst.erase(iter1);
    else
      ++iter1;

  auto iter2 = v.begin();
  while(iter2 != v.end())
    if(*iter2 % 2 == 0)
      iter2 = v.erase(iter2);
    else
      ++iter2;

  cout << "v: " ;
  for(auto i : v)
    cout << i << " ";
  cout << endl;
  cout << "lst: " ;
  for(auto i : lst)
  cout << i << " ";

  return 0;
}
