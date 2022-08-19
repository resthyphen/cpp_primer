#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <stack>
#include <deque>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::list;
using std::array;
using std::to_string;
using std::stack;
using std::deque;

int main(int argc, char const *argv[]) {
  stack<int, vector<int>> intStack;
  deque<int> de;
  for(size_t ix = 0; ix != 10; ++ix)
    intStack.push(ix);

  while(!intStack.empty()){
    int value = intStack.top();
    cout << value << " ";
    intStack.pop();
  }
  return 0;
}
