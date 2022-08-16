#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::istringstream;
using std::deque;

int main(int argc, char const *argv[]) {
  list<int> l{1,2,3,4,5,6,7,8,9,10};
  deque<int> d1, d2;
  auto i1 = d1.end(), i2 = d2.end();
  for(auto i = l.begin(); i != l.end(); ++i){
    cout << *i << " ";
    if(*i % 2 == 0){
      //d1.insert(i1, *i);
      //++i1;
      d1.push_back(*i);
    }
    else{
      //d2.insert(i2, *i);
      //++i2;
      d2.push_back(*i);
    }
  }
  cout << endl;
  for (auto i : d1)
    cout << i << " ";
  cout << endl;
  for(auto i : d2)
    cout << i << " ";
  return 0;
}
