#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::list;
using std::map;
using std::set;
using std::pair;
using std::multimap;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;

vector<int> * func(vector<int> v){
  return new vector<int>(v);
}

void read_func(vector<int> &v){
  int n;
  while(cin >> n)
    v.push_back(n);
}

void print_func(vector<int> &v){
  for(const auto &i : v)
    cout << i << endl;
}

int main(int argc, char const *argv[]) {
  vector<int> v;
  auto p = func(v);
  read_func(*p);
  print_func(*p);
  delete p;
  return 0;
}
