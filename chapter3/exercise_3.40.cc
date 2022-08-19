#include<iostream>
#include<vector>
#include<cstring>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main(int argc, char const *argv[]) {
  char ca1[] = "hello";
  char ca2[] = "world";
  const int sz = strlen(ca2) + strlen(ca1) + 1;
  char ca3[sz];
  strcpy(ca3, ca1);
  strcat(ca3, ca2);
  cout << ca3 << endl;
  return 0;
}
