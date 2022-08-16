#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  do {
    cout << "please enter two string: \n";
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 < s2)
      cout << s1 << " is less than " << s2;
    else if((s1 != "") && (s2 != ""))
      cout << s1 << " is equal to " << s2;
    else
      cout << s2 << " is less than " << s1;
    cout << endl;
  } while(cin);

  return 0;
}
