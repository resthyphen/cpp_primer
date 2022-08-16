#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;



void f(){
  int i = 42;
  auto f = [&i]() -> bool{
                  if(i > 0)
                      return true;
                    else
                      return false;
                };
  while(f()){
    --i;
    cout << i << endl;
  }
}

int main(int argc, char const *argv[]) {
  f();
  return 0;
}
