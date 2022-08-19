#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::ifstream;
using std::ofstream;

int main(int argc, char const *argv[]) {
  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  for(int i =0; i != 10; ++i)
    cout << arr[i];
  return 0;
}
