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
  cout << ((grade > 90) ? "high pass" :
                          grade >= 75 ? "pass" :
                                        grade >= 60 ?  "low pass" : "fail") << endl;

  return 0;
}
