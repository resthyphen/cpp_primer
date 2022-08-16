#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  cout << "input a number: " << endl;
  int n;
  cin >> n;
  if(n % 2 == 0)
    cout << "the number is even" << endl;
  else
    cout << "the number is odd" << endl;
  
  return 0;
}
