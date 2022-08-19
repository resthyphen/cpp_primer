#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int grade;
  cin >> grade;
  if(grade > 90)
    cout << "high pass" << endl;
  else if(grade > 75)
    cout << "pass" << endl;
  else if(grade >= 60)
    cout << "low pass" << endl;
  else
    cout << "fail" << endl;
  return 0;
}
