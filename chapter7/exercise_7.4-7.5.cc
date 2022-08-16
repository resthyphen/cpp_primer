#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

int main(int argc, char const *argv[]) {
  return 0;
}

struct Person{
  string getName() const {return name;}
  string getAdd() const {return address;}
  string name;
  string address;
};
