#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;


vector<int>::iterator func(vector<int>::iterator begin, vector<int>::iterator end, int n){
  auto i = begin;
  for(; i != end; ++i)
    if(*i == n)
      return i;
  cout << "not found" << endl;
  return i;

}

int func(int a, int b){
  int sum;
  sum = a + b;
  return sum;
}

int main(int argc, char const *argv[]) {
  vector<int> v{1,2,3,4,5};
  cout << func(v.begin(), v.end(), 6) << endl;
  return 0;
}
