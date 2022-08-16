#include<iostream>
#include"Sales_item.h"

int main() {
  Sales_item item;
  Sales_item val;
  Sales_item sum;
  std::cin >> sum;
  //std::cout << sum << std::endl;
  while (std :: cin >> item) {
    if(sum.isbn() == item.isbn()){
      sum += item;
    }
    else{
      std::cout << sum << std::endl;
      sum = item;
    }
  }
  std::cout <<sum << std::endl;
  return 0;
}
