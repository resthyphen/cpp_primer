#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  string lettergrade;
  int grade;
  cin >> grade;
  lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50)/10];
  (grade != 100 && grade % 10 > 7) ? lettergrade += '+' : (grade % 10 < 3) ?
                                                                lettergrade += '-' : lettergrade;
  return 0;
}
