#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  //string s;
  //cin >> s;
  //cout << s << endl;
  //string s1, s2;
  //cin >> s1 >> s2;
  //cout << s1 << s2 << endl;
  string word;
  /*while (cin >> word) {
    cout << word << endl;
  }*/
  string line;
  while (getline(cin, line))
    cout << line << endl;
  return 0;
}
