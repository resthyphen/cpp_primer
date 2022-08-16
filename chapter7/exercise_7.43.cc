#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;

class NoDefault{
public:
  NoDefault(int);
  int f() const { return a;}

private:
  int a;
};

NoDefault::NoDefault(int i){
  a = i;
}

class C{
public:
  C() : n(0) {}

private:
  NoDefault n;
};

int main(int argc, char const *argv[]) {
  NoDefault n(8);
  C c;
  cout << n.f() << endl;
  return 0;
}
