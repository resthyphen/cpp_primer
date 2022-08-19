#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  vector<unsigned> scores(11, 0);
  unsigned grade;
  while (cin >> grade) {
    if(grade <= 100)
      ++scores[grade/10];
  }
  for(auto i : scores)
    cout << i << " " << endl;
  return 0;
}
