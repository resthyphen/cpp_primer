#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[]) {

  cout << (~'q') << endl;       //'q' = 113  ~'q' = -(2^8 - 10001110) = -114   ?
  cout << (~'q' << 6) << endl;     //   -(2^14 - 10 0011 1000 0000) = -7296 ?
  return 0;
}
