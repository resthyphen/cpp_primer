#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

class Y;

class X{
  Y *py;
};

class Y{
  X x;
};
