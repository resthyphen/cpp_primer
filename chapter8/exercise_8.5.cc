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

vector<string> &func(string s, vector<string> &v){
  ifstream in(s);
  if(in){
    string word;
    while(in >> word)
      v.push_back(word);
  }else
    cerr << "couldn't open the f" << endl;
  in.close();
  return v;
}

int main(int argc, char const *argv[]) {
  vector<string> v;
  func(argv[1], v);
  for(auto i : v)
    cout << i << "\n\n";
  cout << endl;
  return 0;
}
