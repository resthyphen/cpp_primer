#include<iostream>
int main(int argc, char const *argv[]) {
  int a = 3, b = 4;
  decltype(a) c = a;
  ++c;
  std::cout << c << std::endl;
  std::cout << a << std::endl;
  decltype(a = b) d = a;
  std::cout << d << " " << a <<std::endl; 
  return 0;
}
