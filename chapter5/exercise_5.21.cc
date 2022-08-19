#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  string s;
  string temp;
  cin >> s;
  temp = s;
  bool twice = false;
  while (cin >> s) {
    if(!isupper(s[0]))
      continue;
    if(s != temp)
      temp = s;
    else{
      cout << s << " occurs twice" << endl;
      twice = true;
      break;
    }
  }
  if(!twice)
    cout << "no word was repeated" << endl;
  return 0;
}
