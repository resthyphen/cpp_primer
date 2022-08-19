#include<iostream>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char *argv[]) {
  cout << "All " << argc << " argument"
            << (argc > 1 ? "s are:" : " is:") << endl;
  for (int i = 0; i < argc; ++i)
    cout << i << "\t" << argv[i] << endl;

  return 0;
}
