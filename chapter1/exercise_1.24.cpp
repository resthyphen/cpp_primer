#include<iostream>
#include "Sales_item.h"
int main(int argc, char const *argv[]) {
  int cnt = 1;
  Sales_item item;
  Sales_item temp;
  std::cin >> item;
  temp = item;
  while (std::cin >> item){
    if (temp.isbn() == item.isbn()){
      ++cnt;
    }
    else{
      std::cout << temp.isbn() << " " << cnt << std::endl;
      cnt = 1;
      temp = item;
    }
  }
  std::cout << temp.isbn() << " occurs " << cnt << " times " << std::endl;
  return 0;
}
