#include <iostream>
int main(){
  int val = 10;
 // keep executing the while as long as val is less than or equal to 10
  while (val >= 0) {
    std::cout << val << " " << std::endl;
    --val;
  }

  return 0;
}
