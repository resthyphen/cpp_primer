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

void func(string &s, const string &oldVal, const string &newVal){
  auto iter = s.begin();
  while(iter != s.end()){
    auto temp = iter;
    auto i = oldVal.begin();
    while(i != oldVal.end()){
        if(*temp != *i)
          break;
        ++i;
        ++temp;
    }
    if(i == oldVal.end()){
      iter = s.erase(iter, temp);
      iter = s.insert(iter, newVal.begin(), newVal.end());
      iter += newVal.size();
      //continue;
    }else
      ++iter;
  }
}

int main(int argc, char const *argv[]) {
  string oldVal = "tho";
  string newVal = "though";
  string s;
  getline(cin, s);
  cout << s << endl;
  func(s, oldVal, newVal);
  func(s, "thru", "through");
  cout << s << endl;
  return 0;
}
