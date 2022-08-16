#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
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

int main(int argc, char const *argv[]) {
  map<vector<int>::iterator, int> im;
  map<list<int>::iterator, int> lm; //cannot define map<list<int>::iterator, int> because the iterator of list does not support iterator arithmetic and does not support < operator.

  return 0;
}
