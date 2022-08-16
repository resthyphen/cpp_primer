#include<iostream>
int main() {
  std::cout << "Enter two numbers" << std::endl;
  int v1, v2;
  std::cin >> v1 >> v2;
  int currVal = 0;

  if(v1 >= v2){
    std::cout << "please input again" << std::endl;
    std::cin >> v1 >> v2;
  }


  std::cout << "The number  " << v1 << " to " << v2 << " inclusive is" << std::endl;
  while (v1 <= v2) {
    std::cout << v1 << std::endl;
    ++v1;
  }


  return 0;
}
