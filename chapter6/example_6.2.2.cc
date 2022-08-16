#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// function that takes a reference to an int and sets the given object to zero
void reset(int i) // i is just another name for the object passed to reset
{
  i = 0;          // changes the value of the object to which i refers
}

int main(int argc, char const *argv[]) {
  int j = 42;
  reset(j);
  //cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  return 0;
}
