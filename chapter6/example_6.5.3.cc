#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;

int main(int argc, char const *argv[]) {

  string word;
  cin >> word;
  size_t threshold = 3;
#ifndef NDEBUG
  if (word.size() < threshold)
    cerr << "Error: " << __FILE__
         << " : in function " << __func__
         << " at line " << __LINE__ << endl
         << " Compiled on " << __DATE__
         << " at " << __TIME__ << endl
         << " Word read was \"" << word
         << "\": Length too short" << endl;
#endif
  return 0;
}
