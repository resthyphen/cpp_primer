#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  //vector<int> v{1,2,3,4,5,6,7,8,9};
  //auto iter = v.begin();
  //iter += 2;
  //cout << *iter << endl;
  vector<unsigned> scores(11, 0);
  unsigned grade;
  auto i = scores.begin();
  while (cin >> grade) {
    if(grade <= 100)
      ++*(i + grade/10);
  }
  for(i = scores.begin(); i != scores.end(); ++i)
    cout << *i << " ";
  cout << endl ;
  return 0;
}
