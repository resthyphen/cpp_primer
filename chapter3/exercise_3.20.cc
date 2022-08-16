#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int n;
  int sum;
  vector<int> v;
  while(cin >> n)
    v.push_back(n);
  for(int i = 0; i < v.size() && i+1 < v.size(); i += 2){
    sum = v[i] + v[i + 1];
    cout << sum << " " << endl;
  }
  for(int i = 0; i < v.size() / 2 ; i++){
    sum = v[i] + v[v.size() - 1 - i];
    cout << sum << " " << endl;
  }

  return 0;
}
