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
using std::shared_ptr;

shared_ptr<int> clone(int p){
  //return new int(p);
  return shared_ptr<int>(new int(p));
}

void process(shared_ptr<int> ptr){
  cout << *ptr << endl;
}

int main(int argc, char const *argv[]) {
  //shared_ptr<double> p1 = new double(1024);
  int *x(new int(1024));
  process(shared_ptr<int>(x));
  int j = *x;
  shared_ptr<int> p2(new int(42));
  //cout << j << endl;
  shared_ptr<int> p(new int(42));
  int *q = p.get();
  process(shared_ptr<int>(q));
  int foo = *p;
  cout << foo << endl;
  return 0;
}
