#include<iostream>
#include <vector>
#include <cstring>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main(int argc, char const *argv[]) {
  string s1 = "hello";
  string s2 = "world";
  cout << (s1 <= s2) << endl;
  const char ca1[] = "A string example";
  const char ca2[] = "A different string";
  if(strcmp(ca1, ca2) > 0)
    cout << "ca1 is bigger than ca2" << endl;
  return 0;
}
