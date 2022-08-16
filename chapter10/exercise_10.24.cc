#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
#include <functional>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using namespace std::placeholders;


bool check_size(const string &s, string::size_type sz){
   return s.size() >= sz;
 }

void first_bigger_than(vector<int> &v, const string &s){
  sort(v.begin(), v.end());
  auto iter = partition(v.begin(), v.end(), bind(check_size, s, _1));
  /*
  vector<string> sv;
  auto iter = v.cbegin();
  while (iter != v.cend()) {
    sv.push_back(string(*iter, 'c'));
    cout << *iter << " ";
    ++iter;
  }
  cout << endl;
  auto wc = find_if(sv.begin(), sv.end(), bind(check_size, _1, s.size()));
  auto n = wc - sv.begin();
  iter = v.cbegin();
  iter += n;
  */
  cout << *iter << endl;
}



int main(int argc, char const *argv[]) {
  vector<int> v;
  int i;
  while(cin >> i)
    v.push_back(i);
  first_bigger_than(v, "first");
  return 0;
}
