#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char const *argv[]) {
  const string s = "Keep out!";
  for (auto &c : s) {
    
    cout << c << endl;
  }
  return 0;
}
