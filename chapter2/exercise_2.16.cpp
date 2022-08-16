#include<iostream>
int main(int argc, char const *argv[]) {
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;
  r2 = 3.14159;
  //r2 = r1;
  i = r2;
  r1 = d;
  std::cout << i << " " << r1 << " " << r2 << std::endl;
  return 0;
}
