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

void func(forward_list<string> &flst, string s1, string s2){
  auto prev = flst.before_begin();
  auto iter = flst.begin();
  bool found = false;
  while(iter != flst.end()){
    if(*iter == s1){
      flst.insert_after(iter, s2);
      found = true;
    }
    prev = iter;
    ++iter;
  }
  if(iter == flst.end() && found == false)
    flst.insert_after(prev, s2);
}

int main(int argc, char const *argv[]) {
  string s;
  forward_list<string> flst;
  auto iter = flst.before_begin();
  while (cin >> s) {
    iter = flst.insert_after(iter, s);
  }
  string s1 = "erase";
  string s2 = "the";
  func(flst, s1, s2);
  for(auto i : flst)
    cout << i << endl;
  return 0;
}
