#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << (a > b && b > c && c > d) << endl;

  return 0;
}
