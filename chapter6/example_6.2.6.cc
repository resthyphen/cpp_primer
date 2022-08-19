#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;

void error_msg(initializer_list<string> il)
{
  for(auto &i : il)
    cout << i << endl;
}


int main(int argc, char const *argv[]) {
  error_msg({"functionX", "okay"});
  return 0;
}
