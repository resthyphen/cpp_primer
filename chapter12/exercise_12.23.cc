#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <stdexcept>
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
using std::out_of_range;
using std::exception;

int main(int argc, char const *argv[]) {
  char *c1 = "hello,";        //string literal
  char *c2 = "world";         //string literal
  char *c3 = new char[strlen(c1) + strlen(c2) + 1];
  strcpy(c3, c1);
  strcat(c3, c2);
  cout << c3 << endl;
  delete [] c3;

  string s1 = "hello,";       //library string
  string s2 = "world";
  string s3 = s1 + s2;
  /*
  char *a = new char[s3.size() + 1];
  size_t i;
  for(i = 0; i != s1.size(); ++i)
    *(a + i) = s1[i];
  for(size_t n = 0; n != s2.size(); ++n)
    *(a + i + n) = s2[n];
  */
  cout << s3 << endl;

  return 0;
}
