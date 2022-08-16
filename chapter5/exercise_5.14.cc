#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<string> v;
  vector<string> repWord;
  //vector<int> c;
  string s;
  while (cin >> s) {
    v.push_back(s);
  }
  auto beg = v.begin();
  while(beg != v.end()){
    temp = *beg;
    repWord.push_back(temp);
    ++beg;
    if(temp != *beg){

    }


  }
  return 0;
}
