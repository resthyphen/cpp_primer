#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::stof;

int main(int argc, char const *argv[]) {
  vector<string> v;
  string number;
  int isum = 0;
  float fsum = 0;
  while(cin >> number)
    v.push_back(number);
  auto iter = v.begin();
  while(iter != v.end()){
    isum += stoi(*iter);
    ++iter;
  }
  cout << isum << endl;

  iter = v.begin();
  while(iter != v.end()){
    fsum += stof(*iter);
    ++iter;
  }
  cout << fsum << endl;
  return 0;
}
