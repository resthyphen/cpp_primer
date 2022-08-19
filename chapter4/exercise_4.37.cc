#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char const *argv[]) {
  int i;
  double d;
  const string *ps;
  char *pc;
  void *pv;
  pv = static_cast<void *>(const_cast<string *>(ps));
  //i = int(*pc);
  i = static_cast<int> (*pc);
  //pv = &d;
  pv = static_cast<void *> (&d);
  //pc = (char*) pv;
  pc = static_cast<char*> (pv);
  return 0;
}
