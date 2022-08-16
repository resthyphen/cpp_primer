#include<iostream>
int main(int argc, char const *argv[]) {
  int i = 42;
  int *ip = &i;
  int *&r = ip;

  return 0;
}
