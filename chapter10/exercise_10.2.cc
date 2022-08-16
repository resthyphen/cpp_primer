#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;

int main(int argc, char const *argv[]) {
  list<string> v;
  list<string> r;
  string i;
  while(cin >> i)
    v.push_back(i);

  auto iter1 = v.cbegin();
  auto iter2 = r.begin();

  while(iter1 != v.cend()){
      for(; iter2 != r.end(); ++iter2)
        if(*iter1 == *iter2)
          break;
      if(iter2 == r.end()){
        r.push_back(*iter1);
      }
      iter2 = r.begin();
      ++iter1;
  }


  iter2 = r.begin();
  while (iter2 != r.end()) {
    auto result = count(v.cbegin(), v.cend(), *iter2);
    cout << *iter2 << " appears " <<  result << " times" << endl;
    ++iter2;
  }


  return 0;
}
