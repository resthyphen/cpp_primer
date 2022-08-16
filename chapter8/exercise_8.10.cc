#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::istringstream;

int main(int argc, char const *argv[]) {
  vector<string> v;
  string line;
  string word;
  while(getline(cin, line))
    v.push_back(line);

  for(auto i : v){
    istringstream input(i);
    while(input >> word)
      cout << word << "\n";
    cout << "\n\n";
  }
  cout << endl;
  return 0;
}
