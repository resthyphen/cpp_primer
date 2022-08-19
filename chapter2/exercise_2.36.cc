#include<iostream>
int main(int argc, char const *argv[]) {
  int a = 3, b = 4;
  decltype(a) c = a;
  decltype((b)) d = a;
  ++c;
  ++d;
  std::cout << c << " " << d << " " << a << std::endl;
  return 0;
}
